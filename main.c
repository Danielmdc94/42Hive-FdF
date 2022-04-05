/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:27:37 by dpalacio          #+#    #+#             */
/*   Updated: 2022/04/05 12:31:19 by dpalacio         ###   ########.fr       */
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

void	isometric(int *x, int *y, float z, t_data *data)
{
	*x = ((*x - *y) * cos(0.8));
	*y = ((*x + *y) * sin(0.8) - (z * 2));
}

void	error_print(char *e_string)
{
	ft_putendl(e_string);
	system("leaks myprogram");
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
	data.img = mlx_new_image(data.mlx, WIN_WIDTH,WIN_HEIGHT);
	data.img_addr = mlx_get_data_addr(data.img,&data.px_bits, &data.line_bytes, &data.endian);
	draw(&data);
	controls(&data);
	/*----TEST STRING DRAW----*/
	mlx_string_put(data.mlx, data.win, ((WIN_WIDTH / 2) - 100), 20, YELLOW, "Daniel's Art Class");
	mlx_loop(data.mlx);
}
