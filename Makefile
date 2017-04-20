# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nterol <nterol@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/22 14:31:35 by nterol            #+#    #+#              #
#    Updated: 2017/04/20 17:25:42 by nterol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Werror -Wextra -Ofast

SRC = main.c fractal.c key_hooks.c mouse_hooks.c launcher.c draw.c

OBJ = main.o fractal.o key_hooks.o mouse_hooks.o launcher.o draw.o

LIB = ./libft/libft.a

FRAM = -framework OpenGL -framework Appkit

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft
	make -C ./minilibx_macos/
	gcc -c $(CFLAGS) $(SRC)
	gcc -o $(NAME) $(OBJ) $(LIB) -I minilibx_macos ./minilibx_macos/libmlx.a $(FRAM)

clean :
	rm -rf $(OBJ)
	make -C ./minilibx_macos/ clean
	make -C ./libft/ clean

fclean : clean
	rm -rf $(NAME)

re : fclean all
