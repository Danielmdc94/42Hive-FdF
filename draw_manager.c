/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:51:12 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/23 16:59:21 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_line(t_line line, t_mlx *param)
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
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y, 0xFFFFFF);
		x = x + dx;
		y = y + dy;
		step--;
	}
	return (1);
}

int	draw_wireframe(int x0, int y0, int gap)
{
	int x;
	int y;

	x0 = 50;
	y0 = 50;
	gap = 10;
	
}
