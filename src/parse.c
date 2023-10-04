/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:38:38 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/04 18:47:58 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	init_colomn(char *number, size_t j)
{
	int	colomn;

	colomn = (int)malloc(sizeof(int) * 


	return (colomn);
}

int	**init_map(int fd, int rows)
{
	char	*line;
	int	**map;
	size_t	i;
	size_t	j;

	map = (int **)malloc(sizeof(int) * (rows + 1));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	i = 0;
	while (i < (size_t)rows)
	{
		j = 0;
		while (line[j])
		{
			map[i][j] = init_colomn(line[j], j);
			j++;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = 0;
	return (map);
}


int     map_rows(char *map)
{
        int     fd;
	int	rows;
	char	*line;

        fd = open(map, O_RDONLY);
        if (fd == -1)
        {
                perror("Error opening file\n")
                exit (1);
        }
	line = get_next_line(fd);
	rows = 0;
	while (line)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
        return (rows);
}

int	parse_map(char *map, int rows)
{
	int	**map;
	int	fd;
	int	i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file\n");
		exit (1);
	}
	map = init_map(fd, rows);
	close(fd);
	return (map);
}
