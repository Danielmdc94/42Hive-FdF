/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_controller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:43:31 by dpalacio          #+#    #+#             */
/*   Updated: 2022/04/07 15:09:36 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_fdf(int key, t_data *data)
{
	if (key == 53)
		exit(0);
	return (1);
}

int	pan_view(int key, t_data *data)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 13)
		data->y_off += data->zoom;
	if (key == 0)
		data->x_off += data->zoom;
	if (key == 1)
		data->y_off -= data->zoom;
	if (key == 2)
		data->x_off -= data->zoom;
	if (key == 49)
		offset_draw(data);
	draw(data);
	return (1);
}

int	switch_view(int key, t_data *data)
{
	if (key == 14)
	{
		if (data->zoom == 1)
			data->zoom = 2;
		data->view++;
		draw(data);
	}
	if (key == 12)
	{
		data->view--;
		draw(data);
	}
	if (data->view > 1)
	{
		data->view = 0;
		draw(data);
	}
	if (data->view < 0)
	{
		if (data->zoom == 1)
			data->zoom = 2;
		data->view = 1;
		draw(data);
	}
	return (1);
}

