/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:20:05 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/03 14:27:52 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include "../lib/Libft/libft.h"
#include "../lib/Getnextline/get_next_line_bonus.h"
#include "../lib/Printf/ft_printf.h"
#include "../mlx_linux/mlx.h"
#include <stdlib.h>

#define HEIGHT 1080
#define WIDTH 1920

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	endian;
	int	line_length;
}			t_data;

typedef struct	s_mlx_data
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
}			t_mlx_data;

int	close_window(t_mlx_data *win_data);
void	init_window(t_mlx_data *win_data);

#endif
