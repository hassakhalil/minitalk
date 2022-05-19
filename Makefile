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

NAME = server_bonus

NAME1 = client_bonus

SRC = utils.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ) server_bonus.o 

$(NAME1): $(OBJ) client_bonus.o

all: $(NAME)

clean:
	rm -rf $(OBJ)  server_bonus.o client_bonus.o

fclean: clean
	rm -rf $(NAME) $(NAME1)

re: fclean all