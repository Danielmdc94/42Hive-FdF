/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:51:12 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/25 12:01:59 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_line(t_line line, t_mlx *param, int color)
{
	float	dx;
	float	dy;
	float	step;
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
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y, color);
		x = x + dx;
		y = y + dy;
		step--;
	}
	return (1);
}

int	draw_wireframe(int x0, int y0, int gap, t_mlx *param)
{
	int x;
	int y;
	t_line line;

	y = y0;
	while (y <= 450)
	{
		x = x0;
		while (x <= 450)
		{
			line.x0 = x;
			line.y0 = y;
			line.x1 = x;
			line.y1 = y + gap;
			draw_line(line, param, 0xFFFFFF);
			line.x1 = x + gap;
			line.y1 = y;
			draw_line(line, param, 0xFFFFFF);
			x = x + gap;
		}
		y = y + gap;
	}
	return (1);
}
