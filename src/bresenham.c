/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:22:45 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/13 14:42:28 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int ft_abs(int x)
{
    if (x < 0)
        return (-(x));
    return (x);
}

void  ft_bresenham(t_coordinates pixel_from, t_coordinates pixel_to, t_bresenham *bresenham)
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
	{ 
	   	bresenham->sy = -1;
	}
	bresenham->x = pixel_from.dest_x;
	bresenham->y = pixel_from.dest_y;
    bresenham->err = bresenham->dx - bresenham->dy;
}

void    ft_draw_line(t_coordinates pixel_from, t_coordinates pixel_to, t_mlx_data *win_data)
{
    t_bresenham bresenham;

    ft_bresenham(pixel_from, pixel_to, &bresenham);
    while (1)
    {
        my_mlx_pixel_put(&win_data->img, bresenham.x, bresenham.y, 0x00FF0000);
        if (bresenham.x == pixel_to.dest_x && bresenham.y == pixel_to.dest_y)
            break;
        bresenham.e2 = 2 * bresenham.err;
        if (bresenham.e2 > -bresenham.dy)
        {
            bresenham.err -= bresenham.dy;
            bresenham.x += bresenham.sx;
        }
        if (bresenham.e2 < bresenham.dx)
        {
            bresenham.err += bresenham.dx;
            bresenham.y += bresenham.sy;
        }
    }
}
