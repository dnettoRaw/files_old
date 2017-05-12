# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnetto <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 08:45:07 by dnetto            #+#    #+#              #
#    Updated: 2017/04/11 19:00:00 by dnetto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_display_file
TAG= -Wall -Werror -Wextra
SRC= main.c
OBJ= main.o

all: $(NAME)

$(NAME):
	@echo "\033[33;32m=== compilation de la $(NAME) ==="
	gcc $(TAG) -c $(SRC)
	gcc $(OBJ) -o $(NAME)

clean:
	@echo "\033[31m=== effacer  ==="
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean all
