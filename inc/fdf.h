/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:20:05 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/10 15:04:53 by cbouwen          ###   ########.fr       */
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

#define HEIGHT 1080
#define WIDTH 1920

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

typedef struct	s_coordinates
{
	int	x;
	int	y;
	int	z;
}		t_coordinates;

typedef struct	s_mapinfo
{
	int rows;
	int colomns;
}			t_mapinfo;


void	get_info(t_mapinfo *mapinfo, int fd);
void	ft_map_info(char *argv, t_mapinfo *mapinfo);

t_coordinates	**parse_map(char *argv, t_coordinates ***map, t_mapinfo mapinfo);

void	free_params(t_coordinates ***map, t_mapinfo *mapinfo);
void	ft_free(void *ptr);
void	ft_free_array(t_coordinates **map, int count);

int	close_window(t_mlx_data *win_data);
void	init_window(t_mlx_data *win_data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	print_map(t_coordinates **map, t_mapinfo mapinfo);
#endif
