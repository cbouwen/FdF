/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:24:08 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/09 22:02:30 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	get_info(t_mapinfo *mapinfo, int fd)
{
	char	*line;
	int i;
	
	i = 0;
	line = get_next_line(fd);
//	if (!line)
//		ft_free();//
	mapinfo->colomns = ft_word_count(line, ' ');
	free(line);
	while (line)
	{
		i++;
		line = get_next_line(fd);
		free(line);
	}
	mapinfo->rows = i;
}
		

void	ft_map_info(char *argv, t_mapinfo *mapinfo)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit (1);
	}
//	mapinfo = (t_mapinfo *)malloc(sizeof(t_mapinfo));
//	if (!mapinfo)
//		ft_free();
	get_info(mapinfo, fd);
	close(fd);
}

