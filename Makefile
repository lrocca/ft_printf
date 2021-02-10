# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocca <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/27 18:25:00 by lrocca            #+#    #+#              #
#    Updated: 2021/02/10 18:01:17 by lrocca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -c
SRC			=	ft_printf.c flags.c flags2.c types.c types2.c print.c print2.c
OBJ			= 	$(SRC:.c=.o)
LIBFT		=	$(LIBFTDIR)/libft.a
LIBFTDIR	=	./libft

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	cp $(LIBFT) $@
	ar rcs $@ $^

$(LIBFT):
	make -C $(LIBFTDIR)

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)

re: fclean all

bonus: re

.PHONY: all bonus clean fclean re
