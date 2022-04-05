/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:42:50 by dpalacio          #+#    #+#             */
/*   Updated: 2022/04/05 12:31:14 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	controls(t_data *data)
{
	mlx_key_hook(data->win, key_controller, data);
	mlx_mouse_hook(data->win, mouse_controller, data);
}

void	display_controls(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 20, 25, 0xEAEAEA,
		"CONTROLS:");
	mlx_string_put(ddata->mlx, data->win, 20, 50, 0xEAEAEA,
		"W, A, S, D - Pan view Up, Left, Down, Right");
	mlx_string_put(data->mlx, data->win, 20, 75, 0xEAEAEA,
		"Placeholder");
}

