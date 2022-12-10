# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewolfghe <ewolfghe@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 21:20:53 by ewolfghe          #+#    #+#              #
#    Updated: 2022/09/13 01:27:14 by ewolfghe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
PATH_INCLUDE = ./

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_tolower.c ft_toupper.c ft_strdup.c ft_memset.c ft_bzero.c ft_memcpy.c \
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_atoi.c ft_strchr.c ft_strrchr.c \
		ft_calloc.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
		ft_itoa.c ft_strncmp.c ft_strnstr.c ft_strlcpy.c ft_strlcat.c ft_striteri.c \
		ft_substr.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_split.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	cc $(FLAGS) -I $(PATH_INCLUDE) -c $(SRCS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BONUS_OBJS)
	ar -rc $(NAME) $(BONUS_OBJS)

$(BONUS_OBJS): $(BONUS_SRCS)
	cc $(FLAGS) -I $(PATH_INCLUDE) -c $(BONUS_SRCS)
