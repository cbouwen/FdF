/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:24:08 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/18 13:13:33 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	get_info(t_mapinfo *mapinfo, int fd)
{
	char	*line;
	int i;
	
	i = 0;
	line = get_next_line(fd);
	if (!line)
		ft_free(mapinfo);
	mapinfo->colomns = ft_word_count(line, ' ');
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
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
	get_info(mapinfo, fd);
	close(fd);
}
