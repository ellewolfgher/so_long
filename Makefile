# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 19:37:41 by ewolfghe          #+#    #+#              #
#    Updated: 2022/12/07 19:37:42 by ewolfghe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/so_long.c \
		src/ber_map_check.c \
		src/path_check.c \
		src/game_init.c \
		src/utils.c \
		src/hooks.c

OBJS = $(SRCS:.c=.o)

CC = gcc

MFLAGS = ./libft/libft.a ./mlx/libmlx.a ./ft_printf/libftprintf.a ./get_next_line/get_next_line.a

AFLAGS =  -Wall -Wextra -Werror -I./mlx -I./libft -I./ft_printf -I./get_next_line

RM = rm -rf

NAME = so_long

all :$(MFLAGS) $(NAME)

$(MFLAGS):
	make -C ./libft
	make -C ./get_next_line
	make -C ./ft_printf
	make -C ./mlx

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MFLAGS) $(AFLAGS) -L ./libft/ -lft -L ./mlx/ -lmlx -L ./ft_printf/ -L ./get_next_line/ -lXext -lX11 -lm -lbsd -o $(NAME)

fclean : clean
	make fclean -C ./libft
	make fclean -C ./ft_printf
	make fclean -C ./get_next_line
	$(RM) $(NAME)

clean :
	make clean -C ./libft
	make clean -C ./ft_printf
	make clean -C ./get_next_line
	make clean -C ./mlx
	$(RM) ./src/*.o

re : fclean all

.PHONY : all fclean clean re