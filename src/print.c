/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:48:45 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/10 14:57:59 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_draw_map(t_coordinates **map, t_mapinfo mapinfo, t_mlx_data *win_data)
{
	int	x;
	int	y;

	y = 0;
	while(y < mapinfo.rows)
	{
		x = -1;
		while (++x < mapinfo.colomns)
		{
			my_mlx_pixel_put(&win_data->img, (map[y][x].x) * 10, (map[y][x].y) * 10, 0x00FF0000);
		}
		y++;
	}
}


void	print_map(t_coordinates **map, t_mapinfo mapinfo)
{
	t_mlx_data	win_data;

	win_data.mlx = mlx_init();
	init_window(&win_data);
	ft_draw_map(map, mapinfo, &win_data);
	mlx_loop(win_data.mlx);
}
