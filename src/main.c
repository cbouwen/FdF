/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:07:40 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/17 18:32:54 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	test(t_coordinates **map, t_mapinfo mapinfo)
{
	int	x;
	int	y;

	y = 0;
	while (y < mapinfo.rows)
	{
		x = -1;
		while (++x < mapinfo.colomns)
		{
			ft_printf("Struct[%i][%i]:\nValue of x: %i\nValue of y:%i\nValue of z:%i\n\n", y, x, map[y][x].x, map[y][x].y, map[y][x].z);
			printf("Value of dest_x: %i\nValue of dest_y:%i\n\n", map[y][x].dest_x, map[y][x].dest_y);
		}
		y++;
	}
}

void	test_z(t_coordinates **map, t_mapinfo mapinfo)
{
	int	x;
	int	y;

	y = 0;
	while (y < mapinfo.rows)
	{
		x = -1;
		while (++x < mapinfo.colomns)
		{
			ft_printf("%i ", map[y][x].z);
		}
		ft_printf("\n");
		y++;
	}
}

void	ft_fdf(char *argv) //set free_params somewhere in mlx_loop. key hook of mlx_loop exits and doesn't call on free_params anymore == IS OK. KEEP COMMENT AS REMINDER
{
	t_mapinfo		mapinfo;
	t_coordinates	**map;

	ft_map_info(argv, &mapinfo);
	parse_map(argv, &map, mapinfo);
//	test(map, mapinfo);
//	ft_calculate_iso(&map, &mapinfo);;
	//test_z(map, mapinfo);
	print_map(&map, mapinfo);
//	free_params(&map, &mapinfo);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_fdf(argv[1]);
	ft_printf("\n");
	return (0);
}
