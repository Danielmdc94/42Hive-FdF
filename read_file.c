/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:04:10 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/31 18:55:00 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**read_file(char *file, t_data *data)
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
	(*data).map_height = n_lines;
	file_arr = ft_memalloc(sizeof(char **) * n_lines);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		*file_arr = ft_strdup(line);
		file_arr++;
	}
	return (file_arr - n_lines);
}

t_point	*get_points(char **file, t_data data)
{
	t_point *points;
	int		x;
	int		y;
	int		z;
	int		i;

	x = 0;
	y = 0;
	z = 0;
	i = 0;
	while (y < data.map_height)
	{
		points->y = y;
		while (**file != '\0')
		{
			points->x = x;
			points->z = ft_atoi(*file);
			while(**file != ' ')
				(*file)++;
			(*file)++;
			points++;
			i++;
			x++;
		}
		if (y > 0 && data.map_width != x)
			exit(-1);
		data.map_width = x;
		x = 0;
		file++;
		y++;
	}
	return (points - i);
}
