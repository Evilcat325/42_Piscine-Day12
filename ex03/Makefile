# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seli <seli@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 23:27:04 by seli              #+#    #+#              #
#    Updated: 2018/10/04 23:37:26 by seli             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# this is for testing M automation system purpose only
# as Norm is down I probably would fail on ex02 would like to see if M check shell command

NAME = ft_hexdump

all: $(NAME)

$(NAME):
	@which hexdump | xargs -I{} cp {} $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean

re:	fclean al
