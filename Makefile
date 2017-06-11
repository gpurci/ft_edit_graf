# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpurci <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/03 14:33:32 by gpurci            #+#    #+#              #
#    Updated: 2017/02/13 17:24:40 by gpurci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC = *.c gnl/*.c
FLAGS = -Wall -Werror -Wextra -lmlx -framework OpenGL -framework AppKit

all:
	gcc $(FLAGS) $(SRC) -I libft -L libft -lft

clean:
		rm -rf *.o
