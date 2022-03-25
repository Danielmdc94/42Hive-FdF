/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:54:47 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/25 13:06:36 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx.h"
# include <math.h>

//open()
# include <fcntl.h>

//struct for mlx and window ref.
typedef struct s_mlx{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx;

//struct for start and end points of a line
typedef struct s_line{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}				t_line;

//struct for a wireframe
typedef struct s_wireframe{
	int	x00;
	int	y00;
	int	x01;
	int	y01;
	int	x10;
	int	y10;
	int	x11;
	int	y11;
	int	steps;
}				t_wireframe;


//mouse_controller,c
int	mouse_controller(int button, int x, int y, t_mlx *param);

//key_controller.c
int	key_controller(int key, t_mlx *param);
//draw_manager.c
int	draw_line(t_line line, t_mlx *param, int color);
int	draw_wireframe(int x0, int y0, int gap, t_mlx *param);

#endif
