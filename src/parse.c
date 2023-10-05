/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:38:38 by cbouwen           #+#    #+#             */
/*   Updated: 2023/10/05 18:05:27 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	init_colomn(char *number, size_t colomn)
{
	int	*int_array;
	size_t	i;

	i = 0;
	int_array = (int *)malloc(sizeof(int) * colomn);
	if(!int_array)
		ft_free; //write this
	while (i < colomn)
	{
		int_array[i] = ft_atoi(number[i]);
		//something to skip the spaces?
		i++;
	}
	return (int_array);
}

int	**init_map(int fd, int rows)
{
	char	*line;
	int	**map;
	size_t	i;
	size_t	colomn;

	map = (int **)malloc(sizeof(int) * (rows + 1));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	i = 0;
	colomn = map_colomn(line);
	while (i < (size_t)rows)
	{
		map[i] = init_colomn(line, colomn);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = 0;
	return (map);
}

int	map_colomn(char *line)
{
	size_t	i;

	i = ft_word_count(line, ' ');
	return (i);
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

int	**parse_map(char *argv, int rows)
{
	int	**map;
	int	fd;
	int	i;

	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file\n");
		exit (1);
	}
	map = init_map(fd, rows);
	close(fd);
	return (map);
}
