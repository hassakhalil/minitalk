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

NAME2 = server_bonus

NAME3 = client_bonus

SRC = utils.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ) server.o 

$(NAME1): $(OBJ) client.o

$(NAME2): $(OBJ) server_bonus.o

$(NAME3): $(OBJ) client_bonus.o

all: $(NAME)

clean:
	rm -rf $(OBJ) server.o client.o server_bonus.o client_bonus.o

fclean: clean
	rm -rf $(NAME) $(NAME1) $(NAME2) $(NAME3)

re: fclean all