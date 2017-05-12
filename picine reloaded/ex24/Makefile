# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnetto <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 08:45:07 by dnetto            #+#    #+#              #
#    Updated: 2017/04/11 18:43:21 by dnetto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft
TAG= -Wall -Werror -Wextra
SRC= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OBJ= ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

all: $(NAME)

$(NAME):
	@echo "\033[33;32m=== compilation de la $(NAME) ==="
	gcc $(TAG) -c $(SRC)
	ar rc libft.a $(OBJ) 
	ranlib libft.a

clean:
	@echo "\033[31m=== effacer  ==="
	rm -f $(OBJ)
	
fclean: clean
	rm -f libft.a

re: fclean all
