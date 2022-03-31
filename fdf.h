/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:54:47 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/31 18:47:54 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>

# define WIN_WIDTH	1080
# define WIN_HEIGHT	920

//struct for mlx and window ref.
typedef struct s_data{
	void	*mlx;
	void	*win;
	void	*img;
	int		map_width;
	int		map_height;
}				t_data;

typedef struct s_vector{
	void	**items;
	int		size;
	int		total;
}				t_vector;

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
int		mouse_controller(int button, int x, int y, t_data *data);

//key_controller.c
int		key_controller(int key, t_data *data);
//draw_manager.c
int		draw_line(t_line line, t_data *data, int color);
//read_file.c
char	**read_file(char *file, t_data *data);
t_point	*get_points(char **file, t_data data);
#endif
