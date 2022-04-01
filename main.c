/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:27:37 by dpalacio          #+#    #+#             */
/*   Updated: 2022/04/01 17:45:46 by dpalacio         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include "fdf.h"

void	test_print(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map_height)
	{
		while (x < data->map_width)
		{
			ft_putnbr(data->matrix[y][x]);
			ft_putchar(',');
			ft_putnbr(data->color_matrix[y][x]);
			ft_putchar(9);
			x++;
		}
		ft_putchar('\n');
		ft_putchar('\n');
		ft_putchar('\n');
		y++;
		x = 0;
	}
}

void	error_print(char *e_string)
{
	ft_putendl(e_string);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		error_print("Usage: ./fdf <map_file>");
	read_file(argv[1], &data);
/*------TESTING------*/
	test_print(&data);
/*------END TEST-----*/
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	draw_map(&data);
	mlx_key_hook(data.win, key_controller, &data);
	mlx_mouse_hook(data.win, mouse_controller, &data);
	mlx_string_put(data.mlx, data.win, ((WIN_WIDTH / 2) - 100), 20, YELLOW, "Daniel's Art Class");
	mlx_loop(data.mlx);
}
