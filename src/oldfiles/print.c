/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:48:45 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/12 18:08:41 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	ft_abs(int x)
{
	if (x < 0)
		return (-(x));
	return (x);
}

/*void	ft_bresenham(t_coordinates pixel_from, t_coordinates pixel_to, t_bresenham *bresenham)
{
	bresenham->dx = ft_abs(pixel_to.dest_x - pixel_from.dest_x);
	bresenham->dy = ft_abs(pixel_to.dest_y - pixel_from.dest_y);
	if (pixel_from.dest_x < pixel_to.dest_x)
		bresenham->sx = 1;
	else
		bresenham->sx = -1;
	if (pixel_from.dest_y < pixel_to.dest_y)
		bresenham->sy = 1;
	else
		bresenham->sy = -1;
	bresenham->err = bresenham->dx - bresenham->dy;
}

void	ft_draw_line(t_coordinates pixel_from, t_coordinates pixel_to, t_mlx_data *win_data)
{
	t_bresenham	bresenham;

	ft_bresenham(pixel_from, pixel_to, &bresenham);
	while (1)
	{
		my_mlx_pixel_put(&win_data->img, pixel_from.dest_x, pixel_from.dest_y, 0x00FF0000);
		if (pixel_from.dest_x == pixel_to.dest_x && pixel_from.dest_y == pixel_to.dest_y)
			break;
		bresenham.e2 = 2 * bresenham.err;
		if (bresenham.e2 > -bresenham.dy)
		{
			bresenham.err -= bresenham.dy;
			pixel_from.dest_x += bresenham.sx;
		}
		if (bresenham.e2 < bresenham.dx)
		{
			bresenham.err += bresenham.dx;
			pixel_from.dest_y += bresenham.sy;
		}
	}
}*/

static void	ft_initialize_bresenham_params(t_bresenham *p,
											t_coordinates a,
											t_coordinates b)
{
	p->dx = ft_abs((int)b.x - (int)a.x);
	p->dy = ft_abs((int)b.y - (int)a.y);
	if (a.x < b.x)
		p->sx = 1;
	else
		p->sx = -1;
	if (a.y < b.y)
		p->sy = 1;
	else
		p->sy = -1;
	p->err = p->dx - p->dy;
	p->x = (int)a.x;
	p->y = (int)a.y;
}

static void	ft_draw_line(t_coordinates a,
							t_coordinates b,
							t_mlx_data *win_data)
{
	t_bresenham			p;

	ft_initialize_bresenham_params(&p, a, b);
	while (1)
	{
	//	t = sqrt(pow(p.x - a.x, 2) + pow(p.y - a.y, 2)) / sqrt(pow(b.x - a.x, 2)
	//			+ pow(b.y - a.y, 2));
		my_mlx_pixel_put(&win_data->img, p.x, p.y, 0x00FF0000);
		if (p.x == (int)b.x && p.y == (int)b.y)
			break ;
		p.e2 = 2 * p.err;
		if (p.e2 > -p.dy)
		{
			p.err -= p.dy;
			p.x += p.sx;
		}
		if (p.e2 < p.dx)
		{
			p.err += p.dx;
			p.y += p.sy;
		}
	}
}

void	ft_draw_map(t_coordinates ***map, t_mapinfo mapinfo, t_mlx_data *win_data)
{
	int	x;
	int	y;

	y = 0;
	while(y < mapinfo.rows)
	{
		x = -1;
		while (++x < mapinfo.colomns)
		{
//			if ((*map)[y][x].dest_x >= 0 && (*map)[y][x].dest_y >= 0 && (*map)[y][x].dest_x <= WIDTH && (*map)[y][x].dest_y <= HEIGHT)
			{
				if (y + 1 < mapinfo.rows)
					ft_draw_line((*map)[y][x], (*map)[y + 1][x], win_data);
				if (x + 1 < mapinfo.colomns)
					ft_draw_line((*map)[y][x], (*map)[y][x + 1], win_data);
			}
		}
		y++;
	}
}


void	ft_draw_coordinates(t_coordinates ***map, t_mapinfo mapinfo, t_mlx_data *win_data)
{
	int	x;
	int	y;

	y = 0;
	while(y < mapinfo.rows)
	{
		x = -1;
		while (++x < mapinfo.colomns)
		{
			if ((*map)[y][x].x >= 0 && (*map)[y][x].y >= 0 && (*map)[y][x].x <= WIDTH && (*map)[y][x].y <= HEIGHT)
				my_mlx_pixel_put(&win_data->img, (*map)[y][x].dest_x, (*map)[y][x].dest_y, 0x00FF0000);
		}
		y++;
	}
}


void	print_map(t_coordinates ***map, t_mapinfo mapinfo)
{
	t_mlx_data	win_data;
	t_display_params	display_params;

	win_data.mlx = mlx_init();
	init_window(&win_data);
	ft_apply_isometrics(map, mapinfo);
	ft_get_display_params(&display_params, *map, mapinfo);
	ft_apply_display_params(display_params, map, mapinfo);
//	test(*map, mapinfo);
//	ft_draw_coordinates(map, mapinfo, &win_data);
//	test_z(*map, mapinfo);
	ft_draw_map(map, mapinfo, &win_data);
	mlx_loop(win_data.mlx);
}
