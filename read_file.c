/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:04:10 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/29 16:57:16 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char ***fill_map(char **file, int n_lines)
{
	char ***map;

	map = ft_memalloc();
	while (n_lines > 0)
	{
		*map = ft_strsplit(*file, ' ');
		file++;
		n_lines--;
		map++;
	}
	return (map);
}

char	**read_file(char *file)
{
	char	**file_arr;
	char	*line;
	int		n_lines;
	int		fd;

	n_lines = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (get_next_line(fd, &line) == 1)
		n_lines++;
	close(fd);
	file_arr = ft_memalloc(sizeof(char **) * n_lines);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		*file_arr = ft_strdup(line);
		file_arr++;
	}
	return(file_arr - n_lines);
}
