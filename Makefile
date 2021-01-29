# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocca <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/27 18:25:00 by lrocca            #+#    #+#              #
#    Updated: 2021/01/29 12:29:12 by lrocca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
SRC			=	ft_printf.c
OBJ			=	$(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(LIBFT):
	make -C ./libft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
