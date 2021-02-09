# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuhan <yuhan@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 18:16:22 by yuhan             #+#    #+#              #
#    Updated: 2021/02/09 22:49:09 by yuhan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_two

SRCDIR = ./srcs/
SRCNAMES = $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC = $(addprefix $(SRCDIR), $(SRCNAMES))
BUILDDIR = ./build/
BUILDOBJS = $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))
INCDIR = ./inc/

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(BUILDDIR) $(NAME)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -o $@ -c $<

$(NAME): $(BUILDOBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(BUILDOBJS)

clean:
	rm -rf $(BUILDDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
