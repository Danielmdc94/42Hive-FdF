/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:54:47 by dpalacio          #+#    #+#             */
/*   Updated: 2022/03/23 16:59:22 by dpalacio         ###   ########.fr       */
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

typedef struct s_line{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}				t_line;

int	mouse_controller(int button, int x, int y, t_mlx *param);
int	key_controller(int key, t_mlx *param);
int	draw_line(t_line line, t_mlx *param);

#endif
