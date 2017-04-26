# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nterol <nterol@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/22 14:31:35 by nterol            #+#    #+#              #
#    Updated: 2017/04/26 14:55:11 by nterol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/
LIB_PATH = ./lib/libft/
MLX_PATH = ./lib/minilibx_macos/

NAME = fractol
CFLAGS = -Wall -Werror -Wextra -Ofast
FRAM = -L$(MLX_PATH) -I$(MLX_PATH) -lmlx -framework OpenGL -framework Appkit

SRC_NAME = main.c fractal.c key_hooks.c mouse_hooks.c draw.c launcher.c\
					reduce_error.c gradient.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft.a

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix, -I, $(INC_PATH))
LIB = $(LIB_PATH)$(LIB_NAME)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIB_PATH) re
	make -C $(MLX_PATH) re
	gcc $(CFLAGS) $(LIB) $(INC) $(OBJ) $(FRAM) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	gcc $(CFLAGS) -I$(MLX_PATH) $(INC) -o $@ -c $<

nolib: $(OBJ)
	gcc $(CFLAGS) $(LIB) $(INC) $(OBJ) $(FRAM) -o $(NAME)

cleanmlx:
	make -C $(MLX_PATH) clean

cleanlib:
	make -C $(LIB_PATH) clean

fcleanlib:
	make -C $(LIB_PATH) fclean


clean : cleanmlx cleanlib
	rm -fv $(OBJ)
	rm -rf $(OBJ_PATH)

fclean : clean fcleanlib
	rm -fv $(NAME)

re : fclean all
