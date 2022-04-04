/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:27:37 by dpalacio          #+#    #+#             */
/*   Updated: 2022/04/04 19:19:12 by dpalacio         ###   ########.fr       */
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
/*
	draw_map(&data);

int color = 0xABCDEF;

if (data.px_bits != 32)
    color = mlx_get_color_value(data.mlx, color);

for(int y = 0; y < WIN_HEIGHT; ++y)
for(int x = 0; x < WIN_WIDTH; ++x)
{
    int pixel = (y * data.line_bytes) + (x * 4);

    if (data.endian == 1)        // Most significant (Alpha) byte first
    {
        data.img_addr[pixel + 0] = (color >> 24);
        data.img_addr[pixel + 1] = (color >> 16) & 0xFF;
        data.img_addr[pixel + 2] = (color >> 8) & 0xFF;
        data.img_addr[pixel + 3] = (color) & 0xFF;
    }
    else if (data.endian == 0)   // Least significant (Blue) byte first
    {
        data.img_addr[pixel + 0] = (color) & 0xFF;
        data.img_addr[pixel + 1] = (color >> 8) & 0xFF;
        data.img_addr[pixel + 2] = (color >> 16) & 0xFF;
        data.img_addr[pixel + 3] = (color >> 24);
    }
}
mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
*/
	mlx_key_hook(data.win, key_controller, &data);
	mlx_mouse_hook(data.win, mouse_controller, &data);
	/*----TEST STRING DRAW----*/
	mlx_string_put(data.mlx, data.win, ((WIN_WIDTH / 2) - 100), 20, YELLOW, "Daniel's Art Class");
	mlx_loop(data.mlx);
}
