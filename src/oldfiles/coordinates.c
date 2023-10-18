/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:28:29 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/12 17:28:27 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void    ft_get_min_max(t_display_params *display_params, t_coordinates **map, t_mapinfo mapinfo)
{
    int x;
    int y;

    display_params->min_x = (float)INT_MAX;
    display_params->max_x = (float)INT_MIN;
    display_params->min_y = (float)INT_MAX;
    display_params->max_y = (float)INT_MIN;
    y = -1;
    while (++y < mapinfo.rows)
    {
        x = -1;
        while (++x < mapinfo.colomns)
        {
            if (map[y][x].x < display_params->min_x)
                display_params->min_x = map[y][x].x;
            if (map[y][x].y < display_params->min_y)
                display_params->min_y = map[y][x].y;
            if (map[y][x].x > display_params->max_x)
                display_params->max_x = map[y][x].x;
            if (map[y][x].y > display_params->max_y)
                display_params->max_y = map[y][x].y;
        }
    }
}

void	ft_apply_display_params(t_display_params display_params, t_coordinates ***map, t_mapinfo mapinfo)
{
	int	x;
	int	y;

	y = -1;
	while (++y < mapinfo.rows)
	{
		x = -1;
		while (++x < mapinfo.colomns)
		{
			(*map)[y][x].x = (*map)[y][x].x * display_params.scale_factor_x + display_params.translate_x;
			(*map)[y][x].y = (*map)[y][x].y * display_params.scale_factor_y + display_params.translate_y;
		}
	}
}

void	ft_get_display_params(t_display_params *display_params, t_coordinates **map, t_mapinfo mapinfo)
{
	ft_get_min_max(display_params, map, mapinfo);
	display_params->scale_factor_x = WIDTH / (display_params->max_x - display_params->min_x);
	display_params->scale_factor_y = HEIGHT / (display_params->max_y - display_params->min_y);
	display_params->translate_x = -(display_params->min_x) * display_params->scale_factor_x;
	display_params->translate_y = -(display_params->min_y) * display_params->scale_factor_y;
}

t_coordinates	ft_project_point(t_coordinates og_point)
{
	t_coordinates	projected_point;

	projected_point.x = og_point.x - og_point.y;
	projected_point.y = (og_point.x + og_point.y) / 2 - og_point.z;
	projected_point.z = og_point.z;
	return (projected_point);
}


void	ft_apply_isometrics(t_coordinates ***map, t_mapinfo mapinfo)
{
	int	y;
	int	x;

	y = -1;
	while (++y < mapinfo.rows)
	{
		x = -1;
		while (++x < mapinfo.colomns)
			(*map)[y][x] = ft_project_point((*map)[y][x]);
	}
}
