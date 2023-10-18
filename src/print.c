/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:42:02 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/18 13:11:57 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_draw_map(t_coordinates **map, t_mapinfo mapinfo, t_mlx_data *win_data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < mapinfo.rows)
	{
		x = -1;
		while (++x < mapinfo.colomns)
		{
			if (y + 1 < mapinfo.rows)
				ft_draw_line(map[y][x], map[y + 1][x], win_data);
			if (x + 1 < mapinfo.colomns)
				ft_draw_line(map[y][x], map[y][x + 1], win_data);
		}
	}
}

void    print_map(t_coordinates ***map, t_mapinfo mapinfo)
{
    t_mlx_data  win_data;

    win_data.mlx = mlx_init();
    init_window(&win_data);
	ft_calculate_map(map, mapinfo);
	ft_draw_map(*map, mapinfo, &win_data);
	free_params(map, &mapinfo);
    mlx_loop(win_data.mlx);
}

