/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:42:50 by dpalacio          #+#    #+#             */
/*   Updated: 2022/04/28 14:20:14 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	controls(t_data *data)
{
	mlx_hook(data->win, 3, 0, on_keyup, data);
	mlx_hook(data->win, 2, 0, on_keydown, data);
	mlx_hook(data->win, 4, 0, on_mousedown, data);
}

int	on_keydown(int key, t_data *data)
{
	pan_view(key, data);
	switch_view(key, data);
	change_height(key, data);
	change_angle(key, data);
	return (1);
}

int	on_keyup(int key, t_data *data)
{
	exit_fdf(key, data);
	return (1);
}

int	on_mousedown(int key, int x, int y, t_data *data)
{
	mouse_wheel(key, x, y, data);
	right_click(key, x, y, data);
	return (1);
}
