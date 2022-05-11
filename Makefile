# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 14:57:57 by hkhalil           #+#    #+#              #
#    Updated: 2022/04/26 14:58:06 by hkhalil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

NAME1 = client

SRC = utils.c ft_printf_utils.c ft_printf.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ) server.o 

$(NAME1): $(OBJ) client.o
	cc $(CFLAGS) $(OBJ) client.o -o client

all: $(server)

clean:
	rm -rf $(OBJ)  server.o client.o

fclean: clean
	rm -rf $(NAME) $(NAME1)

re: fclean all