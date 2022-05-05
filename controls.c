/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:42:50 by dpalacio          #+#    #+#             */
/*   Updated: 2022/05/05 15:32:27 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//Holds the hooks for every event controlling the program
void	controls(t_data *data)
{
	mlx_hook(data->win, 3, 0, on_keyup, data);
	mlx_hook(data->win, 2, 0, on_keydown, data);
	mlx_hook(data->win, 4, 0, on_mousedown, data);
	mlx_hook(data->win, 17, 0, exit_fdf, data);
}

//Holds the controls for every keydown event (press key)
int	on_keydown(int key, t_data *data)
{
	pan_view(key, data);
	switch_view(key, data);
	change_height(key, data);
	change_angle(key, data);
	return (1);
}

//Holds the controls for every keyup event (release key)
int	on_keyup(int key, t_data *data)
{
	if (key == 53)
		exit_fdf(data);
	return (1);
}

//Holds the controls for every mouse event (scroll and click)
int	on_mousedown(int key, int x, int y, t_data *data)
{
	mouse_wheel(key, x, y, data);
	right_click(key, x, y, data);
	return (1);
}
