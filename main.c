/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:27:37 by dpalacio          #+#    #+#             */
/*   Updated: 2022/04/13 15:45:41 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(int *x, int *y, t_data *data)
{
	*x = *x * cos(data->rot_angle) - *y * sin(data->rot_angle);
	*y = *y * cos(data->rot_angle) + *x * sin(data->rot_angle);
}

void	isometric(int *x, int *y, int z, t_data *data)
{
	*x = ((*x - *y) * cos(data->iso_angle));
	*y = ((*x + *y) * sin(data->iso_angle) - (z / 4));
}

void	error_print(char *e_string)
{
	ft_putendl(e_string);
	system("leaks fdf");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		error_print("Usage: ./fdf <map_file>");
	data.color_scheme = 1;
	read_file(argv[1], &data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	data.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.img_addr = mlx_get_data_addr(data.img, &data.px_bits,
			&data.line_bytes, &data.endian);
	offset_draw(&data);
	draw(&data);
	controls(&data);
	ft_putnbr(data.color_scheme);
	mlx_loop(data.mlx);
}
