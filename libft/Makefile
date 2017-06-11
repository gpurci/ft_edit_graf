# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpurci <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/16 16:37:04 by gpurci            #+#    #+#              #
#    Updated: 2016/11/21 17:28:49 by gpurci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
OBJ = *.o
SRC = *.c
NAME = libft.a
FLAGS = -Wall -Werror -Wextra -c

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ):
	gcc $(FLAGS) $(SRC)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
