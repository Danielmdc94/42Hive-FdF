/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:16:23 by dpalacio          #+#    #+#             */
/*   Updated: 2022/04/13 15:08:57 by dpalacio         ###   ########.fr       */
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

int	left_click(int key, int x, int y, t_data *data)
{
	return (1);
}

int	right_click(int key, int x, int y, t_data *data)
{
	return (1);
}
