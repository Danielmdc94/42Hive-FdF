/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:51:12 by dpalacio          #+#    #+#             */
/*   Updated: 2022/04/04 19:35:08 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	offset_draw(t_data *data);
t_line	make_line(t_data *data, char *dir, int x, int y);

void	draw(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(data->mlx, WIN_WIDTH,WIN_HEIGHT);
	if (!data->img)
		error_print("Error(4): Image not allocated");
	data->img_addr = mlx_get_data_addr(data->img,&data->px_bits, &data->line_bytes, &data->endian);
	if (!data->img_addr)
		error_print("Error(4): Image address not allocated");
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
	data->img = NULL;
	data->img_addr = NULL;
}

void	img_pixel_put(t_data *data, int x, int y, int color)
{
	char *pixel;

	if (data->px_bits != 32)
		color = mlx_get_color_value(data->mlx, color);
	pixel = data->img_addr + (y * data->line_bytes) + (x * (data->px_bits / 8));
	*(unsigned int *)pixel = color;
}

int	draw_line(t_line line, t_data *data, int c0, int c1)
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
	while (step >= 0)
	{
		img_pixel_put(data, x, y, color_gradient(c0, c1, step));
	//	mlx_pixel_put(data->mlx, data->win, x, y, color_gradient(c0, c1, step));
		c0 = color_gradient(c0, c1, step);
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
			draw_line(make_line(data, "horizontal", x, y), data,
				data->color_matrix[y][x], data->color_matrix[y][x + 1]);
			if (y < data->map_height - 1)
				draw_line(make_line(data, "vertical", x, y), data,
					data->color_matrix[y][x], data->color_matrix[y + 1][x]);
			x++;
		}
		if (y < data->map_height - 1)
			draw_line(make_line(data, "vertical", x, y), data,
				data->color_matrix[y][x], data->color_matrix[y + 1][x]);
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
