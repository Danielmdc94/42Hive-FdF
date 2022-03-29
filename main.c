/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:27:37 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/29 16:53:19 by dpalacio         ###   ########.fr       */
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

	i = 3;
	if (argc != 2)
		return (0);
	file = read_file(argv[1]);
	while (i > 0)
	{
		ft_putendl(*file);
		file++;
		i--;
	}
	fill_map(file, 3);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	data.mlx_ptr = mlx_ptr;
	data.win_ptr = win_ptr;
	mlx_key_hook(win_ptr, key_controller, &data);
	mlx_mouse_hook(win_ptr, mouse_controller, &data);
	mlx_string_put(mlx_ptr, win_ptr, 150, 20, 0xFFFF00, "Daniel's Art Class");
//	draw_wireframe(wireframe, &mlx, 0xFFFFFF);
	mlx_loop(mlx_ptr);
}
