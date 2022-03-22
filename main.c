/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:27:37 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/22 15:27:14 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_mlx *param)
{
	ft_putnbr(key);
	ft_putchar('\n');
	mlx_pixel_put(param->mlx_ptr, param->win_ptr, 500, 520, 0xFFFFFF);
	return (1);
}


int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_mlx	mlx;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "mlx 42");
	mlx.mlx_ptr = mlx_ptr;
	mlx.win_ptr = win_ptr;

	mlx_pixel_put(mlx_ptr, win_ptr, 500, 500, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, &mlx);
	mlx_loop(mlx_ptr);
}
