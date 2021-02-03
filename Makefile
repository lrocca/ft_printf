# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocca <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/27 18:25:00 by lrocca            #+#    #+#              #
#    Updated: 2021/02/03 14:50:23 by lrocca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -c
FILES		=	ft_printf.c flags.c types.c xtypes.c print.c
SRC			=	$(addprefix $(SRCDIR)/,$(FILES))
OBJ			= 	$(patsubst $(SRCDIR)%,$(OBJDIR)%,$(SRC:.c=.o))
OBJDIR		=	./obj
SRCDIR		=	./src

all: libft $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

libft:
	make -C ./libft

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

test: $(NAME)
	gcc test.c $^ libft/libft.a && ./a.out && rm ./a.out

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
