/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:03:11 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/05 15:03:18 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_line	horizontal_line(t_data *data, int x, int y);
static t_line	vertical_line(t_data *data, int x, int y);

//Draws the given map in the screen
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

//makes horizontal lines based on projection and perspective from each map point
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
		axonometric(&temp_x, &temp_y, data->matrix[y][x], data);
	line.x0 = temp_x + data->x_off;
	line.y0 = temp_y + data->y_off;
	temp_x = (x * data->zoom);
	temp_y = (y * data->zoom);
	temp_x += data->zoom;
	rotate(&temp_x, &temp_y, data);
	if (data->view == 1)
		axonometric(&temp_x, &temp_y, data->matrix[y][x + 1], data);
	line.x1 = temp_x + data->x_off;
	line.y1 = temp_y + data->y_off;
	return (line);
}

//makes vertical lines based on perspective from each map point
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
		axonometric(&temp_x, &temp_y, data->matrix[y][x], data);
	line.x0 = temp_x + data->x_off;
	line.y0 = temp_y + data->y_off;
	temp_x = (x * data->zoom);
	temp_y = (y * data->zoom);
	temp_y += data->zoom;
	rotate(&temp_x, &temp_y, data);
	if (data->view == 1)
		axonometric(&temp_x, &temp_y, data->matrix[y + 1][x], data);
	line.x1 = temp_x + data->x_off;
	line.y1 = temp_y + data->y_off;
	return (line);
}

//Moves each point to a new spot in the screen based on rotation of perspective
void	rotate(int *x, int *y, t_data *data)
{
	*x = *x * cos(data->rot_angle) - *y * sin(data->rot_angle);
	*y = *y * cos(data->rot_angle) + *x * sin(data->rot_angle);
}

//Moves each point to a new spot in the screen based on perspective
void	axonometric(int *x, int *y, int z, t_data *data)
{
	*x = ((*x - *y) * cos(data->axo_angle));
	*y = ((*x + *y) * sin(data->axo_angle) - (z / 4));
}
