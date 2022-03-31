/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:27:37 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/31 18:53:50 by dpalacio         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	t_data	data;
	char	**file;
	t_point	*points;
	int		i;

	if (argc != 2)
		return (0);
	file = read_file(argv[1], &data);
	i = data.map_height;
	while (i > 0)
	{
		ft_putendl(*file);
		file++;
		i--;
	}
	ft_putnbr(data.map_height);

	points = get_points(file, data);
	ft_putnbr((points[40]).z);
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	data.mlx = mlx;
	data.win = win;
	mlx_key_hook(win, key_controller, &data);
	mlx_mouse_hook(win, mouse_controller, &data);
	mlx_string_put(mlx, win, ((WIN_WIDTH / 2) - 100), 20, 0xFFFF00, "Daniel's Art Class");
	mlx_loop(mlx);
}
