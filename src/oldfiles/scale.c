/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:21:41 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/12 13:28:39 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

double	deg_to_rad(int degree)
{
	return (degree * M_PI / 180.0F);
}


void	calculate_iso(t_coordinates ***map, t_mapinfo mapinfo)
{
	int	x;
	int	y;

	y = -1;
	while (++y < mapinfo.rows)
	{
		x = -1;
		while (++x < mapinfo.colomns)
		{
			(*map)[y][x].dest_x = (*map)[y][x].y * cos(deg_to_rad(angle)) - (*map)[y][x].x * cos(deg_to_rad(angle));
			//(*map)[y][x].dest_x = (*map)[y][x].x + cos(deg_to_rad(angle)) * (*map)[y][x].z - cos(deg_to_rad(angle)) * (*map)[y][x].y;
			//ft_printf("(-(*map)[%i][%i].y) = %i\nsin(angle) = %d\n(*map)[%i][%i].z = %i\n\n", y, x, (-(*map)[y][x].y), sin(angle), y, x, (*map)[y][x].z);
			(*map)[y][x].dest_y = (-(*map)[y][x].z) * cos(deg_to_rad(angle * 2)) + (*map)[y][x].x * sin(deg_to_rad(angle));
			//(*map)[y][x].dest_y = (-(*map)[y][x].y) * sin(deg_to_rad(angle)) - (*map)[y][x].z * sin(deg_to_rad(angle));
			//ft_printf("(*map)[%i][%i].y = %i\n\n", y, x, (*map)[y][x].y);
		}
	}
}

/*void	calculate_iso(t_coordinates ***map, t_mapinfo mapinfo)
{
	int	x;
	int	y;
	double y_prime;

	y = -1;
	while (++y < mapinfo.rows)
	{
		x = -1;
		while (++x < mapinfo.colomns)
		{
			y_prime = (*map)[y][x].y * sqrt(2) / 2;
			(*map)[y][x].dest_x = (*map)[y][x].x - (*map)[y][x].z;
			//ft_printf("(-(*map)[%i][%i].y) = %i\nsin(angle) = %d\n(*map)[%i][%i].z = %i\n\n", y, x, (-(*map)[y][x].y), sin(angle), y, x, (*map)[y][x].z);
			(*map)[y][x].dest_y = y_prime + ((*map)[y][x].x + (*map)[y][x].z) / 2;
			//ft_printf("(*map)[%i][%i].y = %i\n\n", y, x, (*map)[y][x].y);
		}
	}
}
*/

void	ft_resize(t_coordinates ***map, t_mapinfo mapinfo)
{
	int	x;
	int	y;

	if (mapinfo.min_x < 0)
	{
		y = -1;
		while (++y < mapinfo.rows)
		{
			x = -1;
			while (++x < mapinfo.colomns)
				(*map)[y][x].dest_x -= mapinfo.min_x;
		}
	}
	if (mapinfo.min_y < 0)
	{
		y = -1;
		while (++y < mapinfo.rows)
		{
			x = -1;
			while (++x < mapinfo.colomns)
				(*map)[y][x].dest_y -= mapinfo.min_y;
		}
	}

}

void	apply_scale(t_coordinates ***map, t_mapinfo mapinfo)
{
	int	x;
	int	y;

	y = -1;
	while (++y < mapinfo.rows)
	{
		x = -1;
		while (++x < mapinfo.colomns)
		{
			(*map)[y][x].dest_x *= mapinfo.scale_x;
			(*map)[y][x].dest_y *= mapinfo.scale_y;
		}
	}	
}

void	apply_offset(t_coordinates ***map, t_mapinfo mapinfo)
{
	int	x;
	int	y;

	y = -1;
	while (++y < mapinfo.rows)
	{
		x = -1;
		while (++x < mapinfo.colomns)
		{
			(*map)[y][x].dest_x += 500; //WIDTH / 2;
			(*map)[y][x].dest_y += 1080;
		}
	}	
}

void	calculate_scale(t_coordinates **map, t_mapinfo *mapinfo)
{
	int	x;
	int	y;

	mapinfo->min_x = INT_MAX;
	mapinfo->min_y = INT_MAX;
	mapinfo->max_x = INT_MIN;
	mapinfo->max_y = INT_MIN;
	y = -1;
	while (++y < mapinfo->rows)
	{
		x = -1;
		while (++x < mapinfo->colomns)
		{
			if (map[y][x].dest_x < mapinfo->min_x)
				mapinfo->min_x = map[y][x].dest_x;
			if (map[y][x].dest_y < mapinfo->min_y)
				mapinfo->min_y = map[y][x].dest_y;
			if (map[y][x].dest_x > mapinfo->max_x)
				mapinfo->max_x = map[y][x].dest_x;
			if (map[y][x].dest_y > mapinfo->max_y)
				mapinfo->max_y = map[y][x].dest_y;
		}
	}
	mapinfo->scale_x = 60;//WIDTH / (mapinfo->max_x - mapinfo->min_x);
	mapinfo->scale_y = 30;//HEIGHT / (mapinfo->max_y - mapinfo->min_y);
}

void	calculate_map(t_coordinates ***map, t_mapinfo *mapinfo)
{
	calculate_iso(map, *mapinfo);
	calculate_scale(*map, mapinfo);
	ft_resize(map, *mapinfo);
	apply_scale(map, *mapinfo);
//	apply_offset(map, *mapinfo);
}
