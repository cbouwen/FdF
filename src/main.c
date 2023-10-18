/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:07:40 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/18 13:12:13 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_fdf(char *argv)
{
	t_mapinfo		mapinfo;
	t_coordinates	**map;

	ft_map_info(argv, &mapinfo);
	parse_map(argv, &map, mapinfo);
	print_map(&map, mapinfo);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_fdf(argv[1]);
	ft_printf("\n");
	return (0);
}
