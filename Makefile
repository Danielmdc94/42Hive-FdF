# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpalacio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 12:22:28 by dpalacio          #+#    #+#              #
#    Updated: 2022/03/22 12:46:43 by dpalacio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = clang

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./libft/ -I /usr/local/include

LIB = -L ./libft -lft -L /usr/local/lib/ -lmlx

FW = -framework OpenGL -framework AppKit

SRC = main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/ re
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) $(LIB) $(FW) -o $(NAME)

clean:
	@make -C libft/ clean
	/bin/rm -f *.o

fclean: clean
	@make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
