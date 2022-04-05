/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:42:50 by dpalacio          #+#    #+#             */
/*   Updated: 2022/04/05 17:57:49 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	controls(t_data *data)
{
//	mlx_key_hook(data->win, key_controller, data);
//	mlx_mouse_hook(data->win, mouse_controller, data);
	mlx_hook(data->win, 3, (1L<<0), exit_fdf, data);
	mlx_hook(data->win, 2, (1L<<1), pan_view, data);
	mlx_hook(data->win, 4, (1L<<2), mouse_wheel, data);
}

void	display_controls(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 25, WIN_HEIGHT - 150, 0xEAEAEA,
		"KEY BINDS:");
	mlx_string_put(data->mlx, data->win, 25, WIN_HEIGHT - 125, 0xEAEAEA,
		"W, A, S, D - Pan view Up, Left, Down, Right");
	mlx_string_put(data->mlx, data->win, 25, WIN_HEIGHT - 100, 0xEAEAEA,
		"Q, E - Rotate Left, Right");
	mlx_string_put(data->mlx, data->win, 25, WIN_HEIGHT - 75, 0xEAEAEA,
		"SPACE - Reset view");
	mlx_string_put(data->mlx, data->win, 525, WIN_HEIGHT - 150, 0xEAEAEA,
		"MOUSE CONTROLLS:");
	mlx_string_put(data->mlx, data->win, 525, WIN_HEIGHT - 125, 0xEAEAEA,
		"MOUSE WHEEL UP - Zoom in");
	mlx_string_put(data->mlx, data->win, 525, WIN_HEIGHT - 100, 0xEAEAEA,
		"MOUSE WHEEL DOWN - Zoom out");
}

void	draw_ui(t_data *data)
{
	int x;
	int y;

	x = 0;
	y  = 0;
	while (y < WIN_HEIGHT)
	{
		while (x < WIN_WIDTH)
		{
			if ((y > 45 && y < 50) || (y > WIN_HEIGHT - 175 && y < WIN_HEIGHT - 170))
				img_pixel_put(data, x, y, 0x696969);
			else if (y < 45 || y > WIN_HEIGHT - 170)
				img_pixel_put(data, x, y, 0x424242);
			else
				img_pixel_put(data, x, y, 0xFFFFFFFF);
			x++;
		}
		x = 0;
		y++;
	}
}
