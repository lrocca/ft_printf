# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocca <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/27 18:25:00 by lrocca            #+#    #+#              #
#    Updated: 2021/02/06 16:34:54 by lrocca           ###   ########.fr        #
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
LIBFT		=	$(LIBFTDIR)/libft.a
LIBFTDIR	=	./libft

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^ $(LIBFT)

$(LIBFT):
	make -C $(LIBFTDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

test: all
	@gcc test.c $(NAME) libft/libft.a && ./a.out && rm ./a.out

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all bonus clean fclean re
