# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnetto <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 08:45:07 by dnetto            #+#    #+#              #
#*   Updated: 2017/04/19 21:46:14 by dnetto           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME= libft.a
TAG= -Wall -Werror -Wextra
SRC= *.c
OBJ= $(SRC:.c=.o)
NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m
ERROR_COLOR=\x1b[31;01m
WARN_COLOR=\x1b[33;01m
OK_STRING=$(OK_COLOR)[OK]$(NO_COLOR)
ERROR_STRING=$(ERROR_COLOR)[ERRORS]$(NO_COLOR)
WARN_STRING=$(WARN_COLOR)[WARNINGS]$(NO_COLOR)

.PHONY: all clean fclean re nr

all: $(NAME)
	
$(NAME):
	@echo "\033[32m======= make =======\033[0m"
	@$ gcc $(TAG) -c $(SRC) 2> temp.log || touch temp.errors
	@echo "gcc\t\c"
	@if test -e temp.errors; then echo "$(ERROR_STRING)$(ERROR_COLOR)" && \
		cat temp.log && echo "$(NO_COLOR)"; elif test -s temp.log; then echo\
	   	"$(WARN_STRING)$(WARN_COLOR)" && cat temp.log && echo "$(NO_COLOR)";\
	   	else echo "\t$(OK_STRING)"; fi;
	@$	ar rc $(NAME) $(OBJ) 2> temp.log || touch temp.errors
	@echo "ar rc\t\c"
	@if test -e temp.errors; then echo "$(ERROR_STRING)$(ERROR_COLOR)" && \
		cat temp.log && echo "$(NO_COLOR)"; elif test -s temp.log; then echo\
	   	"$(WARN_STRING)$(WARN_COLOR)" && cat temp.log && echo "$(NO_COLOR)";\
	   	else echo "\t$(OK_STRING)"; fi;
	@$	ranlib $(NAME) 2> temp.log || touch temp.errors
	@echo "ranlib\t\c"
	@if test -e temp.errors; then echo "$(ERROR_STRING)$(ERROR_COLOR)" && \
		cat temp.log && echo "$(NO_COLOR)"; elif test -s temp.log; then echo\
	   	"$(WARN_STRING)" && echo "$(WARN_COLOR)\c" && cat temp.log && echo\
	   	"$(NO_COLOR)\c"; else echo "\t$(OK_STRING)"; fi;
	@$ rm -f temp.errors temp.log
	
clean:
	@echo "\033[31m====== effacer =====\033[0m"
	@$	rm -f $(OBJ) 2> temp.log || touch temp.errors
	@echo "clean\t\c"
	@if test -e temp.errors; then echo "$(ERROR_STRING)" && cat temp.log;\
	   	elif test -s temp.log; then echo "$(WARN_STRING)" && cat temp.log;\
	   	else echo "\t$(OK_STRING)"; fi;
	@$ rm -f temp.errors temp.log

		
fclean: clean
	@$	rm -f $(NAME) 2> temp.log || touch temp.errors
	@echo "fclean\t\c"
	@if test -e temp.errors; then echo "$(ERROR_STRING)" && cat temp.log;\
	   	elif test -s temp.log; then echo "$(WARN_STRING)" && cat temp.log;\
	   	else echo "\t$(OK_STRING)"; fi;
	@$ rm -f temp.errors temp.log

re: fclean all

nr: re
	@echo "\033[36m==== norminette ====\033[0m"
	@$	norminette $(SRC) > n.log
	@cat n.log | grep -B 1 'Error' | cut -c8- > enorm.log
	@echo "norm\t\c"
	@if test ! -s enorm.log; then echo "\t$(OK_STRING)"; \
		else echo "$(ERROR_STRING)" && cat enorm.log; fi;
	@$ rm -f n.log enorm.errors enorm.log
	@echo "\033[31m====== effacer =====\033[0m"
	@$	rm -f $(OBJ) 2> temp.log || touch temp.errors
	@echo "clean\t\c"
	@if test -e temp.errors; then echo "$(ERROR_STRING)" && cat temp.log;\
	   	elif test -s temp.log; then echo "$(WARN_STRING)" && cat temp.log;\
	   	else echo "\t$(OK_STRING)"; fi;
	@$ rm -f temp.errors temp.log


