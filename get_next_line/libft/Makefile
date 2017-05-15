# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnetto <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 08:45:07 by dnetto            #+#    #+#              #
#*   Updated: 2017/05/13 15:43:55 by dnetto           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME= libft.a
TAG= -Wall -Werror -Wextra
SRC=	ft_afficher_tree.c ft_contnoeud_tree.c ft_bzero.c\
	ft_atoi.c ft_ajouterdata_tree.c ft_creer_noeud.c\
	ft_intlen.c ft_creer_tree.c ft_effacer_tree.c\
	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
	ft_isprint.c ft_isesp.c	ft_isnumeric.c ft_lstadd.c\
	ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_memalloc.c\
	ft_convertbase.c ft_itoa.c ft_lstnew.c\
	ft_memchr.c ft_memcmp.c	ft_memccpy.c ft_memcpy.c\
	ft_memdel.c ft_putchar.c ft_memset.c ft_putchar_fd.c\
	ft_putendl.c ft_putendl_fd.c ft_memmove.c ft_moyenne.c\
	ft_putnbr.c ft_putstr_fd.c ft_putstr.c ft_putnbr_fd.c\
	ft_strclr.c ft_strcat.c	ft_strcpy.c ft_strdel.c\
	ft_strcmp.c ft_strchr.c	ft_strequ.c ft_striter.c\
	ft_strdup.c ft_striteri.c ft_strlen.c ft_strlcat.c\
	ft_strjoin.c ft_strmap.c ft_strncat.c ft_strmapi.c\
	ft_strnequ.c ft_strncpy.c ft_strncmp.c ft_strnew.c\
	ft_strrchr.c ft_strnstr.c ft_strstr.c ft_strsub.c\
	ft_strtrim.c ft_strsplit.c ft_swap.c ft_tolower.c\
	ft_toupper.c ft_strlen_tool.c ft_tree_to_tab.c\
	ft_power.c ft_strrev.c ft_lstmap.c
OBJ= $(SRC:.c=.o)

.PHONY: all clean fclean re nr

all: $(NAME)
	
$(NAME):
	@$	gcc $(TAG) -c $(SRC)
	@$	ar rc $(NAME) $(OBJ)
	@$	ranlib $(NAME) 	
clean:
	@$	rm -f $(OBJ) 		
fclean: clean
	@$	rm -f $(NAME) 
re: fclean all
