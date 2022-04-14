/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:51:12 by dpalacio          #+#    #+#             */
/*   Updated: 2022/04/14 13:40:06 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_line	horizontal_line(t_data *data, int x, int y);
static t_line	vertical_line(t_data *data, int x, int y);

void	draw_map(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < data->map_height)
	{
		while (x < data->map_width - 1)
		{
			draw_line(horizontal_line(data, x, y), data,
				data->color_matrix[y][x], data->color_matrix[y][x + 1]);
			if (y < data->map_height - 1)
				draw_line(vertical_line(data, x, y), data,
					data->color_matrix[y][x], data->color_matrix[y + 1][x]);
			x++;
		}
		if (y < data->map_height - 1)
			draw_line(vertical_line(data, x, y), data,
				data->color_matrix[y][x], data->color_matrix[y + 1][x]);
		x = 0;
		y++;
	}
}

static t_line	horizontal_line(t_data *data, int x, int y)
{
	t_line	line;
	int		temp_x;
	int		temp_y;

	temp_x = x;
	temp_y = y;
	temp_x = (x * data->zoom);
	temp_y = (y * data->zoom);
	rotate(&temp_x, &temp_y, data);
	if (data->view == 1)
		isometric(&temp_x, &temp_y, data->matrix[y][x], data);
	line.x0 = temp_x + data->x_off;
	line.y0 = temp_y + data->y_off;
	temp_x = (x * data->zoom);
	temp_y = (y * data->zoom);
	temp_x += data->zoom;
	rotate(&temp_x, &temp_y, data);
	if (data->view == 1)
		isometric(&temp_x, &temp_y, data->matrix[y][x + 1], data);
	line.x1 = temp_x + data->x_off;
	line.y1 = temp_y + data->y_off;
	return (line);
}

static t_line	vertical_line(t_data *data, int x, int y)
{
	t_line	line;
	int		temp_x;
	int		temp_y;

	temp_x = x;
	temp_y = y;
	temp_x = (x * data->zoom);
	temp_y = (y * data->zoom);
	rotate(&temp_x, &temp_y, data);
	if (data->view == 1)
		isometric(&temp_x, &temp_y, data->matrix[y][x], data);
	line.x0 = temp_x + data->x_off;
	line.y0 = temp_y + data->y_off;
	temp_x = (x * data->zoom);
	temp_y = (y * data->zoom);
	temp_y += data->zoom;
	rotate(&temp_x, &temp_y, data);
	if (data->view == 1)
		isometric(&temp_x, &temp_y, data->matrix[y + 1][x], data);
	line.x1 = temp_x + data->x_off;
	line.y1 = temp_y + data->y_off;
	return (line);
}

/*t_line	make_line(t_data *data, char *dir, int x, int y)
{
	t_line	line;
	int		temp_x;
	int		temp_y;

	temp_x = x;
	temp_y = y;
	temp_x = (x * data->zoom);
	temp_y = (y * data->zoom);
	rotate(&temp_x, &temp_y, data);
	if (data->view == 1)
		isometric(&temp_x, &temp_y, data->matrix[y][x], data);
	line.x0 = temp_x + data->x_off;
	line.y0 = temp_y + data->y_off;
	temp_x = (x * data->zoom);
	temp_y = (y * data->zoom);
	if (ft_strcmp(dir, "horizontal") == 0)
	{
		temp_x += data->zoom;
		rotate(&temp_x, &temp_y, data);
		if (data->view == 1)
			isometric(&temp_x, &temp_y, data->matrix[y][x + 1], data);
	}
	if (ft_strcmp(dir, "vertical") == 0)
	{
		temp_y += data->zoom;
		rotate(&temp_x, &temp_y, data);
		if (data->view == 1)
			isometric(&temp_x, &temp_y, data->matrix[y + 1][x], data);
	}
	line.x1 = temp_x + data->x_off;
	line.y1 = temp_y + data->y_off;
	return (line);
}*/
