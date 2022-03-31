/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:51:12 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/31 17:58:44 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_line(t_line line, t_data *data, int color)
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
		mlx_pixel_put(data->mlx, data->win, x, y, color);
		x = x + dx;
		y = y + dy;
		step--;
	}
	return (1);
}
/*
int	draw_wireframe(t_wireframe wireframe, t_mlx *param, int color)
{
	t_line	line;
	int		x;
	int		y;
	int		steps;

	x = wireframe.x0;
	y = wireframe.y0;
	steps = wireframe.steps;
	while (steps > 0)
	{
		line.x0 = x;
		line.y0 = y;
		line.x1 = wireframe.x1;
		line.y1 = y;
		draw_line(line, param, color);
		y = y + (y - wireframe.y0) / wireframe.steps;
		steps--;
	}
	x = wireframe.x0;
	y = wireframe.y0;
	steps = wireframe.steps;
	while (steps > 0)
	{
		line.x0 = x;
		line.y0 = y;
		line.x1 = x;
		line.y1 = wireframe.y1;
		draw_line(line, param, color);
		x = x + (x - wireframe.x0) / wireframe.steps;
		steps--;
	}

	return (1);
}*/
