/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:16:34 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/10 11:46:35 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	ft_find_z(char *line, t_mapinfo mapinfo, int x)
{
	static size_t	i;
	int				z;

	z = ft_atoi(line + i);
	while (line[i] != ' ')
	{
		if (line[i] == '\0')
			break;
		i++;
	}
	while (line[i] == ' ')
		i++;
	if (mapinfo.colomns == x + 1)
		i = 0;
	return (z);
}

static void	ft_find_coordinates(char *argv, t_mapinfo mapinfo, t_coordinates ***map) //line error protect?
{
	int	x;
	int	y;
	int	fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		free_params(map, &mapinfo);
	line = get_next_line(fd);
	y = 0;
	while (y < mapinfo.rows)
	{
		x = -1;
		while (++x < mapinfo.colomns)
		{
			(*map)[y][x].x = x;
			(*map)[y][x].y = y;
			(*map)[y][x].z = ft_find_z(line, mapinfo, x);
		}
		free(line);
		line = get_next_line(fd);
		y++;
	}
	close(fd);
}

	

static t_coordinates	**init_map(t_mapinfo mapinfo)
{
	t_coordinates	**map;
	int				i;

	i = 0;
	map = (t_coordinates **)malloc(sizeof(t_coordinates *) * mapinfo.rows);
	if (!map)
		ft_free(&mapinfo);
	while (i < mapinfo.rows)
	{
		map[i] = (t_coordinates *)malloc(sizeof(t_coordinates) * mapinfo.colomns);
		if (!map[i])
		{
			ft_free_array(map, i);
			ft_free(&mapinfo);
		}
		i++;
	}
	return(map);
}


t_coordinates	**parse_map(char *argv, t_coordinates ***map, t_mapinfo mapinfo)
{
	*map = init_map(mapinfo);
	ft_find_coordinates(argv, mapinfo, map);
	return (*map);
}
	

