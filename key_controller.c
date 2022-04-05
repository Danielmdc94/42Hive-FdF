/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_controller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:43:31 by dpalacio          #+#    #+#             */
/*   Updated: 2022/04/05 18:42:42 by dpalacio         ###   ########.fr       */
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
