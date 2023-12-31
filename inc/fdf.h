/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:20:05 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/18 10:26:33 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "../lib/Libft/libft.h"
#include "../lib/Getnextline/get_next_line_bonus.h"
#include "../lib/Printf/ft_printf.h"
#include "../mlx_linux/mlx.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
 
#define HEIGHT 2050
#define WIDTH 3800
#define angle 45
#define scale 200

//mlx struct for image
typedef struct	s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	endian;
	int	line_length;
}			t_data;

//mlx struct for window initialization
typedef struct	s_mlx_data
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
}			t_mlx_data;

//struct for map coordinates
typedef struct	s_coordinates
{
	float	x;
	float	y;
	int	z;
	float dest_x;
	float dest_y;

}		t_coordinates;

//struct for map limits
typedef struct	s_mapinfo
{
	int		rows;
	int		colomns;
}			t_mapinfo;
/*
typedef struct s_bresenham
{
	int			x;
	int			y;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
//	int			color_start;
//	int			color_end;
}				t_bresenham;
*/
//resize the window
typedef struct s_display_params
{
	float		min_x;
	float		max_x;
	float		min_y;
	float		max_y;
	int			scale_x;
	int			scale_y;
	int			offset_x;
	int			offset_y;
}				t_display_params;

//struct for Bresenham
typedef struct	s_bresenham
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;	
}				t_bresenham;

void	get_info(t_mapinfo *mapinfo, int fd);
void	ft_map_info(char *argv, t_mapinfo *mapinfo);

t_coordinates	**parse_map(char *argv, t_coordinates ***map, t_mapinfo mapinfo);

void	free_params(t_coordinates ***map, t_mapinfo *mapinfo);
void	ft_free(void *ptr);
void	ft_free_array(t_coordinates **map, int count);

int	close_window(t_mlx_data *win_data);
void	init_window(t_mlx_data *win_data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	print_map(t_coordinates ***map, t_mapinfo mapinfo);

//void	calculate_map(t_coordinates ***map, t_mapinfo *mapinfo);
void	ft_apply_isometrics(t_coordinates ***map, t_mapinfo mapinfo);

void	ft_get_display_params(t_display_params *display_params, t_coordinates **map, t_mapinfo mapinfo);
void	ft_apply_display_params(t_display_params display_params, t_coordinates ***map, t_mapinfo mapinfo);

//void	ft_draw_line(t_coordinates a, t_coordinates b, t_mlx_data *win_data);
void	ft_draw_line(t_coordinates pixel_from, t_coordinates pixel_to, t_mlx_data *win_data);

void	ft_calculate_scale(t_display_params *p, t_coordinates ***map, t_mapinfo mapinfo);

void    ft_calculate_map(t_coordinates ***map, t_mapinfo mapinfo);

#endif
