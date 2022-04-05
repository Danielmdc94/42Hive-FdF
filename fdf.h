/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:54:47 by dpalacio          #+#    #+#             */
/*   Updated: 2022/04/05 12:31:20 by dpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>

/*----RESOLUTION----*/
# define WIN_WIDTH	1080
# define WIN_HEIGHT	920
/*------COLORS------*/
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define YELLOW		0xFFFF00
# define CYAN		0x00FFFF
# define MAGENTA	0xFF00FF

/*-------DATA-------*/
typedef struct s_data{
	void	*mlx;
	void	*win;
	void	*img;
	int		px_bits;
	int		line_bytes;
	int		endian;
	char	*img_addr;
	int		map_width;
	int		map_height;
	int		**matrix;
	int		**color_matrix;
	int		zoom;
	int		x_off;
	int		y_off;
}				t_data;

/*-------LINE------*/
typedef struct s_line{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}				t_line;

/*-------POINT------*/
typedef struct s_point{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

/*-------MAIN-------*/
void	error_print(char *e_string);
void	isometric(int *x, int *y, float z, t_data *data);

/*-----CONTROLS-----*/
void	controls(t_data *data);
void	display_controls(t_data *data);
//mouse_controller,c
int		mouse_controller(int button, int x, int y, t_data *data);

//key_controller.c
int		key_controller(int key, t_data *data);
void	draw(t_data *data);
//draw_manager.c
int		draw_line(t_line line, t_data *data, int color0, int color1);
void	draw_map(t_data *data);
void	img_pixel_put(t_data *data, int x, int y, int color);
/*---COLOR MANAGER--*/
int		rgb_to_hex(int red, int blue, int green);
int		hex_to_red(int hex);
int		hex_to_green(int hex);
int		hex_to_blue(int hex);
void	choose_color(t_data *data, int x, int y);
/*--COLOR GRADIENT--*/
int		color_gradient(int c0, int c1, int steps);
//read_file.c
void	read_file(char *file, t_data *data);
#endif
