/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:16:23 by dpalacio          #+#    #+#             */
/*   Updated: 2022/04/11 17:24:25 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_wheel(int key, int x, int y, t_data *data)
{
	if (key == 4)
	{
		data->zoom += 1;
		data->x_off -= data->map_width / 2;
		data->y_off -= data->map_height / 2;
		draw(data);
	}
	if (key == 5)
	{
		if (data->zoom > 1)
		{
			data->zoom -= 1;
			if (data->zoom == 1 && data->view == 1)
				data->zoom = 2;
			else
			{
				data->x_off += data->map_width / 2;
				data->y_off += data->map_height / 2;
			}
			draw(data);
		}
	}
	return (1);
}
/*
int	mouse_controller(int button, int x, int y, t_data *data)
{
	t_line		line;
	static int	x_save;
	static int	y_save;
	static int	color;
	int			rgb;

	if (!color)
		color = 0;
	if (!x_save)
		x_save = -1;
	if (!y_save)
		y_save = -1;
	ft_putnbr(button);
	ft_putchar('\n');
	line.x0 = x_save;
	line.y0 = y_save;
	if (color == 0)
		rgb = 0xFFFFFF;
	if (color == 1)
		rgb = 0xFFFF00;
	if (color == 2)
		rgb = 0xFF0000;
	if (color == 3)
		rgb = 0x0000FF;
	if (color == 4)
		rgb = 0x00FF00;
	if (color > 4)
	{
		color = 0;
		rgb = 0xFFFFFF;
	}
	if (button == 1)
	{
		if (x_save <= 0 && y_save <= 0)
		{
			x_save = x;
			y_save = y;
		}
		else
		{
			line.x1 = x;
			line.y1 = y;
			draw_line(line, data, rgb, rgb);
			x_save = -1;
			y_save = -1;
		}
	}
	if (button == 2)
	{
		if (x_save <= 0 && y_save <= 0)
		{
			x_save = x;
			y_save = y;
		}
		else
		{
			line.x1 = x;
			line.y1 = y;
			draw_line(line, data, rgb, rgb);
		}
	}
	if (button == 3)
	{
		if (x_save <= 0 && y_save <= 0)
		{
			x_save = x;
			y_save = y;
		}
		else
		{
			line.x1 = x;
			line.y1 = y;
			draw_line(line, data, rgb, rgb);
			x_save = x;
			y_save = y;
		}
	}
	if (button == 4)
//		color = color + 1;
	{
		data->zoom += 1;
		ft_putnbr(data->zoom);
		draw(data);
	}
	if (button == 5)
//		color = color - 1;
	{
		if (data->zoom > 1)
			data->zoom -= 1;
		ft_putnbr(data->zoom);
		draw(data);
	}

	return (1);
}*/
