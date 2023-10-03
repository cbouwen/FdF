/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:07:40 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/03 14:29:16 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char **argv)
{
	(void)argv;
	t_mlx_data	win_data;

	win_data.mlx = mlx_init();	
	if (argc == 2)
	{
		//check_valid_map(argv[1]);
		//parse_map(argv[1]);
		//print_map(argv[1]);
	}
	init_window(&win_data);
	mlx_loop(win_data.mlx);
}

