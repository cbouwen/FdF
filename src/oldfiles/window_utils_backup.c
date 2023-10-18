/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils_backup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:28:21 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/10 15:16:41 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int     handle_input(int key, t_mlx_data *win_data)
{
        if (key == 65307)
        {
                ft_printf("The %d key (ESC) has been pressed\n\n", key);
		close_window(win_data);
        }
        ft_printf("The %d key has been pressed\n\n", key);
        return (0);
}

int	close_window(t_mlx_data *win_data)
{
	mlx_destroy_window(win_data->mlx, win_data->mlx_win);
	mlx_destroy_image(win_data->mlx, win_data->img.img);
	mlx_destroy_display(win_data->mlx);
	free(win_data->mlx);
	exit (1);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_make_square(t_data *img)
{
	int	x;
	int	y;

	x = 500;
	while (x < 1500)
	{
		y = 250;
		while (y < 750)
		{
			my_mlx_pixel_put(img, x, y, 0x00FF0000);
			y++;
		}
		x++;
	}
}

void	init_window(t_mlx_data *win_data)
{
	win_data->mlx_win = mlx_new_window(win_data->mlx, WIDTH, HEIGHT, "FdF");
	win_data->img.img = mlx_new_image(win_data->mlx, WIDTH, HEIGHT);
	win_data->img.addr = mlx_get_data_addr(win_data->img.img, &win_data->img.bits_per_pixel, &win_data->img.line_length, &win_data->img.endian);
	ft_make_square(&win_data->img);
	mlx_put_image_to_window(win_data->mlx, win_data->mlx_win, win_data->img.img, 0, 0);
	mlx_hook(win_data->mlx_win, 17, 1L<<17, &close_window, win_data);
	mlx_key_hook(win_data->mlx_win, handle_input, win_data);
}
