/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:46:58 by dpalacio          #+#    #+#             */
/*   Updated: 2022/04/14 11:49:29 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_controls(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 25, WIN_HEIGHT - 160, 0xf6f095,
		"KEYBOARD:");
	mlx_string_put(data->mlx, data->win, 35, WIN_HEIGHT - 135, 0xEAEAEA,
		"W, A, S, D - Pan view Up, Left, Down, Right");
	mlx_string_put(data->mlx, data->win, 35, WIN_HEIGHT - 110, 0xEAEAEA,
		"Q, E - Rotate Left, Right");
	mlx_string_put(data->mlx, data->win, 35, WIN_HEIGHT - 85, 0xEAEAEA,
		"SPACE - Reset view");
	mlx_string_put(data->mlx, data->win, 35, WIN_HEIGHT - 60, 0xEAEAEA,
		"V - Switch projection view");
	mlx_string_put(data->mlx, data->win, 35, WIN_HEIGHT - 35, 0xEAEAEA,
		"ESC - Quit program");
	mlx_string_put(data->mlx, data->win, 525, WIN_HEIGHT - 160, 0xf6f095,
		"MOUSE:");
	mlx_string_put(data->mlx, data->win, 535, WIN_HEIGHT - 135, 0xEAEAEA,
		"LEFT CLICK - Placeholder");
	mlx_string_put(data->mlx, data->win, 535, WIN_HEIGHT - 110, 0xEAEAEA,
		"RIGHT CLICK - Placeholder");
	mlx_string_put(data->mlx, data->win, 535, WIN_HEIGHT - 85, 0xEAEAEA,
		"WHEEL CLICK - Placeholder");
	mlx_string_put(data->mlx, data->win, 535, WIN_HEIGHT - 60, 0xEAEAEA,
		"WHEEL UP - Zoom in");
	mlx_string_put(data->mlx, data->win, 535, WIN_HEIGHT - 35, 0xEAEAEA,
		"WHEEL DOWN - Zoom out");
	display_info(data);
}

void	display_info(t_data *data)
{
	if (data->view == 0)
		mlx_string_put(data->mlx, data->win, 25, 70, 0xf6f095,
			"TOP-DOWN");
	if (data->view == 1)
		mlx_string_put(data->mlx, data->win, 25, 70, 0xf6f095,
			"ISOMETRIC");
}

void	draw_ui(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		while (x < WIN_WIDTH)
		{
			if ((y > 45 && y < 50)
				|| (y > WIN_HEIGHT - 175 && y < WIN_HEIGHT - 170))
				img_pixel_put(data, x, y, 0x696969);
			else if (y < 45 || y > WIN_HEIGHT - 170)
				img_pixel_put(data, x, y, 0x424242);
			else if (y == 45 || y == WIN_HEIGHT - 170)
				img_pixel_put(data, x, y, 0x000000);
			else
				img_pixel_put(data, x, y, 0xFFFFFFFF);
			x++;
		}
		x = 0;
		y++;
	}
}