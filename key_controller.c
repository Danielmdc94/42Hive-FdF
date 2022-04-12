/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:43:31 by dpalacio          #+#    #+#             */
/*   Updated: 2022/04/12 14:25:56 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_fdf(int key, t_data *data)
{
	if (key == 53)
	{
//		system("leaks fdf");
		exit(0);
	}
	return (1);
}

int	pan_view(int key, t_data *data)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 13)
		data->y_off += data->zoom + 5;
	if (key == 0)
		data->x_off += data->zoom + 5;
	if (key == 1)
		data->y_off -= data->zoom + 5;
	if (key == 2)
		data->x_off -= data->zoom + 5;
	if (key == 49)
	{
		data->iso_angle = 0.5;
		offset_draw(data);
		if (data->view == 1)
			data->x_off *= 2;
	}
	draw(data);
	return (1);
}

int	switch_view(int key, t_data *data)
{
	if (key == 9)
	{
		if (data->zoom <= 1 && data->view == 0)
			data->zoom = 2;
		data->view++;
		if (data->view > 1)
			data->view = 0;
		if (data->view == 1)
			data->x_off += data->zoom * data->map_width / 2;
		if (data->view == 0)
			data->x_off -= data->zoom * data->map_width / 2;
		data->iso_angle = 0.5;
		draw(data);
	}
	return (1);
}

int	change_height(int key, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (key == 15 || key == 3)
	{
		while (y < data->map_height)
		{
			while (x < data->map_width)
			{
				if (data->matrix[y][x] != 0)
				{
					if (key == 15)
						data->matrix[y][x] *= 1.5;
					else
						data->matrix[y][x] /= 1.5;
				}
				x++;
			}
			x = 0;
			y++;
		}
	}
	draw(data);
	return (1);
}

int	change_angle(int key, t_data *data)
{
	if (key == 17 && data->view == 1 && data->iso_angle >= 0)
	{
			data->iso_angle -= 0.05;
			data->y_off += 20;
	}
	if (key == 5 && data->view == 1 && data->iso_angle < 1)
	{
		data->iso_angle += 0.05;
		data->y_off -= 20;
	}
	if (key == 12 && data->view == 1 && data->rot_angle > -0.4)
	{
		data->rot_angle -= 0.05;
		data->x_off -= 40;
		data->y_off -= 10;
	}
	if (key == 14 && data->view == 1 && data->rot_angle < 0.2)
	{
		data->rot_angle += 0.05;
		data->x_off += 40;
		data->y_off += 10;
	}
	draw(data);
	return (1);
}
