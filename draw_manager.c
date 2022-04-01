/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:51:12 by dpalacio          #+#    #+#             */
/*   Updated: 2022/04/01 19:13:00 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	offset_draw(t_data *data);
t_line	make_line(t_data *data, char *dir, int x, int y);

int	draw_line(t_line line, t_data *data, int color)
{
	float	dx;
	float	dy;
	float	step;
	float	x;
	float	y;

	dx = line.x1 - line.x0;
	dy = line.y1 - line.y0;
	x = line.x0;
	y = line.y0;
	if (ft_abs(dx) >= ft_abs(dy))
		step = ft_abs(dx);
	else
		step = ft_abs(dy);
	dx = dx / step;
	dy = dy / step;
	while (step > 0)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, color);
		x = x + dx;
		y = y + dy;
		step--;
	}
	return (1);
}

void	draw_map(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	offset_draw(data);
	while (y < data->map_height)
	{
		while (x < data->map_width - 1)
		{
			draw_line(make_line(data, "horizontal", x, y),
					data, data->color_matrix[y][x]);
			if (y < data->map_height - 1)
				draw_line(make_line(data, "vertical", x, y),
						data, data->color_matrix[y][x]);
			x++;
		}
		if (y < data->map_height - 1)
			draw_line(make_line(data, "vertical", x, y),
					data, data->color_matrix[y][x]);
		x = 0;
		y++;
	}
}
void	offset_draw(t_data *data)
{
	if (data->map_width > data->map_height)
	{
		data->x_off = WIN_WIDTH / 8;
		data->zoom = (WIN_WIDTH - 2 * data->x_off) / data->map_width;
		data->y_off = (WIN_HEIGHT - data->map_height * data->zoom) / 2;
	}
	else
	{
		data->y_off = WIN_HEIGHT / 8;
		data->zoom = (WIN_HEIGHT - 2 * data->y_off) / data->map_height;
		data->x_off = (WIN_WIDTH - data->map_width * data->zoom) / 2;
	}
}

t_line	make_line(t_data *data, char *dir, int x, int y)
{
	t_line	line;

	if (ft_strcmp(dir, "horizontal") == 0)
	{
		line.x0 = (x * data->zoom) + data->x_off;
		line.y0 = (y * data->zoom) + data->y_off;
		line.x1 = (x * data->zoom) + data->x_off + data->zoom;
		line.y1 = (y * data->zoom) + data->y_off;
	}
	if (ft_strcmp(dir, "vertical") == 0)
	{
		line.x0 = (x * data->zoom) + data->x_off;
		line.y0 = (y * data->zoom) + data->y_off;
		line.x1 = (x * data->zoom) + data->x_off;
		line.y1 = (y * data->zoom) + data->y_off + data->zoom;
	}
	return (line);
}
