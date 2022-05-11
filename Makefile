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

SRC = utils.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)

$(NAME1): $(OBJ) client.o
	cc $(CFLAGS) $(OBJ) client.o -o client

all: $(server)

clean:
	rm -rf $(OBJ) $(B_OBJ) checker_bonus.o push_swap.o

fclean: clean
	rm -rf $(NAME) $(B_NAME)

re: fclean all