/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometrics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:12:28 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/18 10:25:42 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_calculate_iso(t_coordinates ***map, t_mapinfo mapinfo)
{
    int x;
    int y;

    y = -1;
    while (++y < mapinfo.rows)
    {
        x = -1;
        while (++x < mapinfo.colomns)
        {
            (*map)[y][x].x = ((*map)[y][x].x - (*map)[y][x].y) * cos(0.5);
            (*map)[y][x].y = ((*map)[y][x].x + (*map)[y][x].y) * sin(0.5) - (*map)[y][x].z;
        }
    }
}

void	ft_find_max_range(t_display_params *display_params, t_coordinates **map, t_mapinfo mapinfo)
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

void	ft_calculate_scale(t_display_params *p, t_coordinates ***map, t_mapinfo mapinfo)
{
	int	x;
	int	y;

(void)map;
(void)mapinfo;

	p->scale_x = (3800 / 4) / (p->max_x - p->min_x);
	p->scale_y = (2050 / 4) / (p->max_y - p->min_y);
	p->offset_x = 50;
	p->offset_y = 50;
   y = -1;
    while (++y < mapinfo.rows)
    {
        x = -1;
        while (++x < mapinfo.colomns)
        {
            (*map)[y][x].dest_x = (*map)[y][x].x;
            (*map)[y][x].dest_y = (*map)[y][x].y;
        }
    }

}

void	ft_apply_params(t_display_params p, t_coordinates ***map, t_mapinfo mapinfo)
{
	int x;
    int y;

    y = -1;
    while (++y < mapinfo.rows)
    {
        x = -1;
        while (++x < mapinfo.colomns)
        {
            (*map)[y][x].dest_x -= p.min_x;
            (*map)[y][x].dest_x = (*map)[y][x].dest_x * p.scale_x + p.offset_x;
            (*map)[y][x].dest_y -= p.min_y;
            (*map)[y][x].dest_y = (*map)[y][x].dest_y * p.scale_y + p.offset_y;
        }
    }
}

void	ft_calculate_map(t_coordinates ***map, t_mapinfo mapinfo)
{
	t_display_params	p;

	ft_calculate_iso(map, mapinfo);
	ft_find_max_range(&p, *map, mapinfo);
	ft_calculate_scale(&p, map, mapinfo);
	ft_apply_params(p, map, mapinfo);
}
