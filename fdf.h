/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:54:47 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/29 16:57:18 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <math.h>

//open()
# include <fcntl.h>

//struct for mlx and window ref.
typedef struct s_data{
	void	*mlx_ptr;
	void	*win_ptr;
	int		map_width;
	int		map_height;
}				t_data;

//struct for start and end points of a line
typedef struct s_line{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}				t_line;

//struct for a point in space
typedef struct s_point{
	int	x;
	int	y;
	int	z;
}				t_point;


//mouse_controller,c
int	mouse_controller(int button, int x, int y, t_data *data);

//key_controller.c
int		key_controller(int key, t_data *data);
//draw_manager.c
int		draw_line(t_line line, t_data *data, int color);
//read_file.c
char	**read_file(char *file);
char	***fill_map(char **file, int n_lines);

#endif
