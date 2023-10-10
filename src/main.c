/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:07:40 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/10 13:54:32 by cbouwen          ###   ########.fr       */
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
		}
		y++;
	}
}

void	ft_fdf(char *argv)
{
	t_mapinfo		mapinfo;
	t_coordinates	**map;

	ft_map_info(argv, &mapinfo);
	parse_map(argv, &map, mapinfo);
	test(map, mapinfo);
	//ft_calculate_iso(&map, &mapinfo);;
	print_map(map, mapinfo);
	free_params(&map, &mapinfo);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_fdf(argv[1]);
	ft_printf("\n");
	return (0);
}
