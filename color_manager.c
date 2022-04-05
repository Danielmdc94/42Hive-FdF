/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:43:09 by dpalacio          #+#    #+#             */
/*   Updated: 2022/04/05 15:05:39 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	choose_color(t_data *data, int x, int y)
{
	if (data->matrix[y][x] <= -100)
		data->color_matrix[y][x] = 0x02445A;
	else if (data->matrix[y][x] > -100 && data->matrix[y][x] <= -50)
		data->color_matrix[y][x] = 0x046C90;
	else if (data->matrix[y][x] > -50 && data->matrix[y][x] <= -20)
		data->color_matrix[y][x] = 0x0495C7;
	else if (data->matrix[y][x] > -20 && data->matrix[y][x] <= 0)
		data->color_matrix[y][x] = 0x02B6F5;
	else if (data->matrix[y][x] > 0 && data->matrix[y][x] <= 10)
		data->color_matrix[y][x] = 0xB5F989;
	else if (data->matrix[y][x] > 10 && data->matrix[y][x] <= 20)
		data->color_matrix[y][x] = 0x84D855;
	else if (data->matrix[y][x] > 20 && data->matrix[y][x] <= 40)
		data->color_matrix[y][x] = 0x39C135;
	else if (data->matrix[y][x] > 40 && data->matrix[y][x] <= 60)
		data->color_matrix[y][x] = 0xF5AC2E;
	else if (data->matrix[y][x] > 40 && data->matrix[y][x] <= 60)
		data->color_matrix[y][x] = 0xC1800F;
	else if (data->matrix[y][x] > 60 && data->matrix[y][x] <= 100)
		data->color_matrix[y][x] = 0x835404;
	else
		data->color_matrix[y][x] = WHITE;
}
