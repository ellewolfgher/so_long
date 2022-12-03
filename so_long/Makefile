# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 16:09:04 by ewolfghe          #+#    #+#              #
#    Updated: 2022/12/03 12:54:19 by ewolfghe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
MLX		=	mlx/libmlx.a
LIB		=	libft/libft.a
COMP	=	-L ./libft/ -lft -L ./mlx/ -lmlx -lXext -lX11 -lm -lbsd
SRC		=	./src/so_long.c ./src/map_init.c ./src/win_arg.c \
			./src/get_next_line.c ./src/hooks.c

OBJ		=	$(SRC:.c=.o)

all:	$(MLX) $(LIB) $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(FLAGS) -o $@ $^ $(COMP)
	
$(MLX):
	@make -s -C mlx
	@echo "MiniLibX successfully compiled!"

$(LIB):
	@make -s C libft
	@echo "Libft successfully compiled!"

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	@make -s $@ -C libft
	@rm -rf $(OBJ)
	@echo "Object Files removed."

fclean:		clean
	@make -s $@ -C libft
	@make -s clean -C mlx
	@rm -rf $(NAME)
	@echo "Binary files removed."

re:		fclean all

.PHONY:		all clean fclean re
