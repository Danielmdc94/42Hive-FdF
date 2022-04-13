# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 12:22:28 by dpalacio          #+#    #+#              #
#    Updated: 2022/04/13 15:29:10 by dpalacio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = clang

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./libft/ -I /usr/local/include

LIB = -L ./libft -lft -L /usr/local/lib/ -lmlx

FW = -framework OpenGL -framework AppKit

SRC = main.c mouse_controller.c key_controller.c draw_manager.c \
	read_file.c color_gradient.c color_manager.c controls.c \
	color_conversion.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/ re
	$(CC) $(INCLUDES) $(SRC) $(LIB) $(FW) -o $(NAME) -flto -g

clean:
	@make -C libft/ clean
	/bin/rm -f *.o

fclean: clean
	@make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
