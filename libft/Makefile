# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnetto <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 08:45:07 by dnetto            #+#    #+#              #
#*   Updated: 2017/04/29 16:43:14 by dnetto           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME= libft.a
TAG= -Wall -Werror -Wextra
SRC=	ft_afficher_tree.c\
		ft_contnoeud_tree.c\
		ft_bzero.c\
		ft_atoi.c\
		ft_ajouterdata_tree.c\
		ft_creer_noeud.c\
		ft_intlen.c\
		ft_creer_tree.c\
		ft_effacer_tree.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_isesp.c\
		ft_isnumeric.c\
		ft_lstadd.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_memalloc.c\
		ft_convertbase.c\
		ft_itoa.c\
		ft_lstnew.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memccpy.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_putchar.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_memmove.c\
		ft_moyenne.c\
		ft_putnbr.c\
		ft_putstr_fd.c\
		ft_putstr.c\
		ft_putnbr_fd.c\
		ft_strclr.c\
		ft_strcat.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strcmp.c\
		ft_strchr.c\
		ft_strequ.c\
		ft_striter.c\
		ft_strdup.c\
		ft_striteri.c\
		ft_strlen.c\
		ft_strlcat.c\
		ft_strjoin.c\
		ft_strmap.c\
		ft_strncat.c\
		ft_strmapi.c\
		ft_strnequ.c\
		ft_strncpy.c\
		ft_strncmp.c\
		ft_strnew.c\
		ft_strrchr.c\
		ft_strnstr.c\
		ft_strstr.c\
		ft_strsub.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_swap.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_strlen_tool.c
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


