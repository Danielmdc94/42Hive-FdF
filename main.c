/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:27:37 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/25 11:55:53 by dpalacio         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_mlx	mlx;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx.mlx_ptr = mlx_ptr;
	mlx.win_ptr = win_ptr;
	mlx_key_hook(win_ptr, key_controller, &mlx);
	mlx_mouse_hook(win_ptr, mouse_controller, &mlx);
	mlx_string_put(mlx_ptr, win_ptr, 150, 20, 0xFFFF00, "Daniel's Art Class");
	draw_wireframe(50, 50, 25, &mlx);
	mlx_loop(mlx_ptr);
}
