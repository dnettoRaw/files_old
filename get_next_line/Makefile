#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/05/10 12:09:17 by dnetto            #+#    #+#             *#
#*   Updated: 2017/05/13 15:46:18 by dnetto           ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME=gnl
CC=gcc
TAGS= -Wall -Werror -Wextra -g
SRC=*.c
OBG=$(SRC:.c=.o)
mklib=make -C libft

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@$(CC) $(TAG) -c $(SRC)
	@$(mklib)
	@$(CC) $(TAG) $(OBG) -o $(NAME) -L libft/ -lft
	@echo "$@ et lib compile\t\033[32m[ok]\033[0m"
clean:
	@rm -f $(OBG)
	@$(mklib) clean
	@echo "$@\t\033[32m[ok]\033[0m"
fclean: clean
	@rm -f $(NAME)
	@$(mklib) fclean
	@echo "$@ \t\033[32m[ok]\033[0m"
re: fclean all 
