# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seli <seli@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 19:14:07 by seli              #+#    #+#              #
#    Updated: 2018/10/04 22:39:06 by seli             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail
CC = gcc
IDIR = includes
SDIR = srcs
CFLAGS = -Wall -Wextra -Werror -I$(IDIR)
SOURCES = ft_main.c ft_stdio.c ft_tail.c
SOURCES := ${SOURCES:%=$(SDIR)/%}

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SOURCES)

clean:
	rm -f $(NAME)

fclean: clean

re:	fclean all
