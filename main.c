/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:27:37 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/31 17:03:53 by dpalacio         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	data;
	char	**file;
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
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fdf");
	data.mlx_ptr = mlx_ptr;
	data.win_ptr = win_ptr;
	mlx_key_hook(win_ptr, key_controller, &data);
	mlx_mouse_hook(win_ptr, mouse_controller, &data);
	mlx_string_put(mlx_ptr, win_ptr, ((WIN_WIDTH / 2) - 100), 20, 0xFFFF00, "Daniel's Art Class");
//	draw_wireframe(wireframe, &mlx, 0xFFFFFF);
	mlx_loop(mlx_ptr);
}
