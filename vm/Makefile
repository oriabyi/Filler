# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oriabyi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/11 15:21:59 by oriabyi           #+#    #+#              #
#    Updated: 2018/11/26 15:23:49 by oriabyi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:         all clean fclean re $(NAME)

CC = gcc
NAME = vm.filler
SRCDIR = src/
SRC =	$(SRCDIR)main.c \
		$(SRCDIR)get_char.c \
		$(SRCDIR)final_score.c \
		$(SRCDIR)auxiliary.c


CFLAGS = -Wall -Wextra -Werror
LIBDIR = ../libft
HEADER = -I ./includes -I $(LIBDIR)libft.h
LIBINCL = -L. $(LIBDIR)/libft.a
OBJFOLD = ./.obj/
OBJ = $(addprefix $(OBJFOLD), $(SRC:.c=.o))

all:            $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBDIR) -f Makefile
	$(CC) $(CFLAGS) $(LIBINCL) $(HEADER) -o $(NAME) $(OBJ) 
	@echo "vm.filler: done"

$(OBJFOLD)%.o: %.c
	@mkdir -p $(OBJFOLD)$(SRCDIR)
	$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

clean:
	@rm -rf $(OBJFOLD)
	@make -C $(LIBDIR) -f Makefile clean
	@echo "objects removed"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) -f Makefile fclean
	@echo "binary removed"

re:             fclean all
