/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:16:23 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/23 16:39:03 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//void	left_click();
//void	right_click();
//void	wheel_click();
//void	wheel_up();
//void	wheel_down();

int	mouse_controller(int button, int x, int y, t_mlx *param)
{
	t_line		line;
	static int	x_save;
	static int	y_save;

	if (!x_save)
		x_save = -1;
	if (!y_save)
		y_save = -1;
	ft_putnbr(button);
	ft_putchar('\n');
	line.x0 = x_save;
	line.y0 = y_save;
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
			draw_line(line, param);
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
			draw_line(line, param);
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
			draw_line(line, param);
			x_save = x;
			y_save = y;
		}
	}
	return (1);
}
