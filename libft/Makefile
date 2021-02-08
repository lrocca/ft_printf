# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocca <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 16:55:45 by lrocca            #+#    #+#              #
#    Updated: 2021/01/18 11:56:12 by lrocca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
BSRC		=	$(wildcard *lst*.c)
SRC			=	$(filter-out $(BSRC), $(wildcard *.c))
OBJ			=	$(SRC:.c=.o)
BOBJ		=	$(BSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(BOBJ)
	ar rcs $(NAME) $(OBJ) $(BOBJ)

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
