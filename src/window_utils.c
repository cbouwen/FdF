/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:28:21 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/13 11:03:40 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	zoom(t_mlx_data *win_data, int key)
{
	(void)win_data;
	if (key == 61)
		ft_printf("You tried to zoom in.\n");
	if (key == 45)
		ft_printf("You tried to zoom out.\n");
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static int     handle_input(int key, t_mlx_data *win_data) //delete ft_printf's
{
        if (key == 65307)
        {
        	ft_printf("The %d key (ESC) has been pressed\n\n", key);
			close_window(win_data);
        }
		if (key == 45)
			zoom(win_data, key);
		if (key == 61)
			zoom(win_data, key);
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

void	init_window(t_mlx_data *win_data)
{
	win_data->mlx_win = mlx_new_window(win_data->mlx, WIDTH, HEIGHT, "FdF");
	win_data->img.img = mlx_new_image(win_data->mlx, WIDTH, HEIGHT);
	win_data->img.addr = mlx_get_data_addr(win_data->img.img, &win_data->img.bits_per_pixel, &win_data->img.line_length, &win_data->img.endian);
	mlx_put_image_to_window(win_data->mlx, win_data->mlx_win, win_data->img.img, 0, 0);
	mlx_hook(win_data->mlx_win, 17, 1L<<17, &close_window, win_data);
	mlx_key_hook(win_data->mlx_win, handle_input, win_data);
}
