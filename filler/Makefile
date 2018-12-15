# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oriabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/11 15:21:59 by oriabyi           #+#    #+#              #
#    Updated: 2018/12/15 13:09:26 by ariabyi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:         all clean fclean re $(NAME)

CC = gcc
NAME = oriabyi.filler
SRCDIR = src/
SRC =	$(SRCDIR)main.c				\
		$(SRCDIR)parsing.c			\
		$(SRCDIR)get_answer.c		\
		$(SRCDIR)auxiliary.c		\
		$(SRCDIR)clean.c			\
		$(SRCDIR)template_num_map.c	\
		$(SRCDIR)init_num_map.c		\
		$(SRCDIR)give_answer.c

CFLAGS = -Wall -Wextra -Werror
HEADER = -I ./includes -I ./libft/libft.h
LIBINCL = -L. libft/libft.a
LIBDIR = ./libft
OBJFOLD = ./.obj/
OBJ = $(addprefix $(OBJFOLD), $(SRC:.c=.o))

all:            $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBDIR) -f Makefile
	$(CC) $(CFLAGS) $(LIBINCL) $(HEADER) -o $(NAME) $(OBJ) 
	@echo "filler: done"

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
