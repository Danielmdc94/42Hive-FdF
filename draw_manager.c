/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:51:12 by dpalacio          #+#    #+#             */
/*   Updated: 2022/04/04 15:15:33 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	offset_draw(t_data *data);
t_line	make_line(t_data *data, char *dir, int x, int y);

int	draw_line(t_line line, t_data *data, int color0, int color1)
{
	float	dx;
	float	dy;
	int		step;
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
		mlx_pixel_put(data->mlx, data->win, x, y, color_gradient(color0, color1, step));
		color0 = color_gradient(color0, color1, step);
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
					data, data->color_matrix[y][x], data->color_matrix[y][x + 1]);
			if (y < data->map_height - 1)
				draw_line(make_line(data, "vertical", x, y),
						data, data->color_matrix[y][x], data->color_matrix[y + 1][x]);
			x++;
		}
		if (y < data->map_height - 1)
			draw_line(make_line(data, "vertical", x, y),
					data, data->color_matrix[y][x], data->color_matrix[y + 1][x]);
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

int	rgb_to_hex(int red, int green, int blue)
{
	int	hex;

	hex = blue + (green << 8) + (red << 16);
	return (hex);
}
int	hex_to_red(int hex)
{
	int	red;

	red = hex >> 16;
	return (red);
}

int	hex_to_green(int hex)
{
	int	green;

	green = (hex & 0x00FF00) >> 8;
	return (green);
}

int	hex_to_blue(int hex)
{
	int	blue;

	blue = (hex & 0x0000FF);
	return (blue);
}

int	color_gradient(int color0, int color1, int steps)
{
	int	red;
	int	green;
	int	blue;

	if (hex_to_red(color0) == hex_to_red(color1))
		red = hex_to_red(color0);
	else
	{
		if (hex_to_red(color0) < hex_to_red(color1))
		red = (hex_to_red(color1) - hex_to_red(color0)) / steps + hex_to_red(color0);
		if (hex_to_red(color1) < hex_to_red(color0))
		red = hex_to_red(color0) - (hex_to_red(color0) - hex_to_red(color1)) / steps;
	}
	if (hex_to_green(color0) == hex_to_green(color1))
		green = hex_to_green(color0);
	else
	{
		if (hex_to_green(color0) < hex_to_green(color1))
		green = (hex_to_green(color1) - hex_to_green(color0)) / steps + hex_to_green(color0);
		if (hex_to_green(color1) < hex_to_green(color0))
		green = hex_to_green(color0) - (hex_to_green(color0) - hex_to_green(color1)) / steps;
	}
	if (hex_to_blue(color0) == hex_to_blue(color1))
		blue = hex_to_blue(color0);
	else
	{
		if (hex_to_blue(color0) < hex_to_blue(color1))
			blue = (hex_to_blue(color1) - hex_to_blue(color0)) / steps + hex_to_blue(color0);
		if (hex_to_blue(color1) < hex_to_blue(color0))
			blue = hex_to_blue(color0) - (hex_to_blue(color0) - hex_to_blue(color1)) / steps;
	}
	return (rgb_to_hex(red, green, blue));
}
