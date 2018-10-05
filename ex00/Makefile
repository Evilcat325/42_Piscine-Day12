# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seli <seli@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 15:56:04 by seli              #+#    #+#              #
#    Updated: 2018/10/04 16:40:16 by seli             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
CC = gcc
IDIR = includes
SDIR = srcs
CFLAGS = -Wall -Wextra -Werror -I$(IDIR)
SOURCES = ft_main.c ft_stdio.c
SOURCES := ${SOURCES:%=$(SDIR)/%}

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SOURCES)

clean:
	rm -f $(NAME)

fclean: clean

re:	fclean all
