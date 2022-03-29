/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:16:23 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/29 16:42:38 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//void	left_click();
//void	right_click();
//void	wheel_click();
//void	wheel_up();
//void	wheel_down();

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
			draw_line(line, data, rgb);
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
			draw_line(line, data, rgb);
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
			draw_line(line, data, rgb);
			x_save = x;
			y_save = y;
		}
	}
	if (button == 4)
		color = color + 1;
	if (button == 5)
		color = color - 1;

	return (1);
}
