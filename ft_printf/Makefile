# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewolfghe <ewolfghe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 11:56:00 by ewolfghe          #+#    #+#              #
#    Updated: 2022/12/07 13:40:44 by ewolfghe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
PATH_INCLUDE = ./

SRCS = ft_printf.c ft_itoa_printf.c ft_putaddress.c ft_putchar.c ft_puthex.c \
		ft_putstr.c ft_utoa.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	cc $(FLAGS) -I $(PATH_INCLUDE) -c $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
