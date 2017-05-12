#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/05/10 12:09:17 by dnetto            #+#    #+#             *#
#*   Updated: 2017/05/10 12:47:49 by dnetto           ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME=gnl
CC=gcc
TAGS= -Wall -Werror -Wextra -g
SRC=*.c
OBG=$(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(TAG) -c $(SRC)
	@echo "$@ \t\033[32m[ok]\033[0m"
	@$(CC) $(TAG) $(OBG) -o $(NAME) -L libft/ -lft
	@echo "$@ \t\033[32m[ok]\033[0m"
clean:
	@rm -f $(OBG)
	@echo "$@ \t\033[32m[ok]\033[0m"
fclean: clean
	@rm -f $(NAME)
	@echo "$@ \t\033[32m[ok]\033[0m"
re: fclean all
