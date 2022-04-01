/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 18:04:10 by dpalacio          #+#    #+#             */
/*   Updated: 2022/04/01 12:32:45 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_width(char *line, t_data *data);

char	**read_file(char *file, t_data *data)
{
	char	**file_arr;
	char	*line;
	int		fd;

	data->map_height = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_print("Error (0): Failed to read");
	while (get_next_line(fd, &line) == 1)
	{
		get_width(line, data);
		data->map_height += 1;
	}
	close(fd);
	file_arr = ft_memalloc(sizeof(char **) * data->map_height);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_print("Error (0): Failed to read");
	while (get_next_line(fd, &line) == 1)
	{
		*file_arr = ft_strdup(line);
		file_arr++;
	}
	return (file_arr - data->map_height);
}

void	get_width(char *line, t_data *data)
{
	int	i;
	int	x;
	int	in;

	i = -1;
	x = 0;
	in = 0;
	while (line[++i])
	{
		if (in && line[i] == ' ')
			in = 0;
		if (!in && line[i] != ' ')
		{
			in = 1;
			x++;
		}
	}
	if (data->map_height == 0)
		data->map_width = x;
	else if (data->map_width != x)
		error_print("Error (1): Map is not rectangular");
	if (data->map_width == 0)
		error_print("Error (2): Empty file");
}

t_point	*make_point_list(char **file, t_data *data)
{
	t_point	*point_list;
	int		x;
	int		y;

	x = 0;
	y = 0;
	point_list = ft_memalloc(sizeof(t_point *) * data->map_height * data->map_width);
	while (y < data->map_height)
	{
		while (x < data->map_width)
		{
			point_list->x = x;
			point_list->y = y;
			point_list->z = ft_atoi(*file);
			point_list++;
			x++;
			while (((**file) - 1) != ' ')
				(*file)++;
		}
		x = 0;
		file++;
		y++;
	}
	return (point_list - (data->map_height * data->map_width));
}
