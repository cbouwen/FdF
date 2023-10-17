/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:42:02 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/17 11:29:29 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_draw_map(t_coordinates **map, t_mapinfo mapinfo, t_mlx_data *win_data)
{
	int	y;
	int	x;

	y = -1;
/*	ft_draw_line(map[4][1], map[1][4], win_data);
	ft_draw_line(map[3][1], map[1][3], win_data);
	ft_draw_line(map[2][1], map[1][2], win_data);
	ft_draw_line(map[4][2], map[2][4], win_data);
	ft_draw_line(map[1][1], map[5][5], win_data);
	ft_draw_line(map[5][1], map[1][5], win_data);
	ft_draw_line(map[1][2], map[4][5], win_data);
	ft_draw_line(map[1][3], map[3][5], win_data);
	ft_draw_line(map[1][4], map[2][5], win_data);
	ft_draw_line(map[5][1], map[1][5], win_data);
	ft_draw_line(map[5][1], map[1][5], win_data);
*/
ft_draw_line(map[1][1], map[8][8], win_data);
	while (++y < mapinfo.rows)
	{
		x = -1;
		while (++x < mapinfo.colomns)
		{
			if (y + 1 < mapinfo.rows)
				ft_draw_line(map[y][x], map[y + 1][x], win_data);
			if (x + 1 < mapinfo.colomns)
				ft_draw_line(map[y][x], map[y][x + 1], win_data);
		//	ft_draw_line(map[0][0], map[5][5], win_data);
		}
	}
//	ft_draw_line(map[1][1], map[5][5], win_data);*/
}

void	ft_apply_isometrics(t_coordinates ***map, t_mapinfo mapinfo)
{
	int	x;
	int	y;

	y = -1;
	while (++y < mapinfo.rows)
	{
		x = -1;
		while (++x < mapinfo.colomns)
		{
			(*map)[y][x].dest_x = (*map)[y][x].x * scale + offset;
			(*map)[y][x].dest_y = (*map)[y][x].y * scale + offset;
		}
	}
}

void    print_map(t_coordinates ***map, t_mapinfo mapinfo)
{
    t_mlx_data  win_data;
//    t_display_params    display_params;

    win_data.mlx = mlx_init();
    init_window(&win_data);
	ft_apply_isometrics(map, mapinfo);
//  ft_get_display_params(&display_params, *map, mapinfo);
// ft_apply_display_params(display_params, map, mapinfo);
	ft_draw_map(*map, mapinfo, &win_data);
//	ft_draw_line((*map)[1][1], (*map)[5][5], &win_data);
	free_params(map, &mapinfo);
    mlx_loop(win_data.mlx);
}

