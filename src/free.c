/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:16:30 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/10 12:58:04 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_free_array(t_coordinates **map, int count)
{
	int	i;

	i = -1;
	while (++i <  count)
		free(map[i]);
	free(map);
}

void	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	write(1, "Error\n", 6);
	exit (1);
}


void	free_params(t_coordinates ***map, t_mapinfo *mapinfo)
{
	int	i;

	i = -1;
	while (++i < mapinfo->rows)
		free((*map)[i]);
	free(*map);
}
