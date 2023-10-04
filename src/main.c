/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:07:40 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/04 18:08:57 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char **argv)
{
	t_mlx_data	win_data;
	int			fd;
	int			rows;
	int			**map;

	win_data.mlx = mlx_init();
	if (argc == 2)
	{
		rows = map_rows(argv[1]);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("Error opening file");
			return (1);
		}
		map = parse_map(argv[1], rows);
		//print_map(argv[1]);
		close(fd);
	}
	init_window(&win_data);
	mlx_loop(win_data.mlx);
	close(fd);
}
