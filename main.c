/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:27:37 by dpalacio          #+#    #+#             */
/*   Updated: 2022/04/01 12:34:50 by dpalacio         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include "fdf.h"

void	error_print(char *e_string)
{
	ft_putendl(e_string);
		exit(1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	**file;
	int		i;//test variable
	t_point *point_list;

	if (argc != 2)
		error_print("Usage: ./fdf <map_file>");
	file = read_file(argv[1], &data);
//	point_list = make_point_list(file, &data);
//test start
	i = data.map_height;
	while (i > 0)
	{
		ft_putendl(*file);
		file++;
		i--;
	}
/*	i = 0;
	while (i < data.map_height * data.map_width)
	{
		if ((i % data.map_width) == 0)
			ft_putchar('\n');
		ft_putnbr(point_list->z);
		ft_putchar(' ');
		i++;
		point_list++;
	}
*/
	ft_putstr("Height: ");
	ft_putnbr(data.map_height);
	ft_putstr("\nWidth: ");
	ft_putnbr(data.map_width);
//test end
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	mlx_key_hook(data.win, key_controller, &data);
	mlx_mouse_hook(data.win, mouse_controller, &data);
	mlx_string_put(data.mlx, data.win, ((WIN_WIDTH / 2) - 100), 20, 0xFFFF00, "Daniel's Art Class");
	mlx_loop(data.mlx);
}
