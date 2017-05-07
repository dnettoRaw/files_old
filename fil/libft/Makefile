# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 18:23:33 by abeauvoi          #+#    #+#              #
#    Updated: 2017/05/04 17:50:48 by abeauvoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= gcc

CFLAGS	+= -Wall -Werror -Wextra

SRCS	= ft_atoi.c \
		  ft_bzero.c \
		  ft_digittoint.c \
		  ft_delcontent.c \
		  ft_error.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_islower.c \
		  ft_isprint.c \
		  ft_isspace.c \
		  ft_isupper.c \
		  ft_itoa.c \
		  ft_isxdigit.c \
		  ft_lstadd.c \
		  ft_lstdel.c \
		  ft_lstdelone.c \
		  ft_lstnew.c \
		  ft_lstiter.c \
		  ft_lstmap.c \
		  ft_lstsize.c \
		  ft_lststrsplit.c \
		  ft_lstpush.c \
		  ft_memalloc.c \
		  ft_memccpy.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memdel.c \
		  ft_memmove.c \
		  ft_memset.c \
		  ft_pow.c \
		  ft_putchar.c \
		  ft_putchar_fd.c \
		  ft_putendl.c \
		  ft_putendl_fd.c \
		  ft_putnbr.c \
		  ft_putnbr_fd.c \
		  ft_putstr.c \
		  ft_putstr_fd.c \
		  ft_revstr.c \
		  ft_strcat.c \
		  ft_strchr.c \
		  ft_strclr.c \
		  ft_strcpy.c \
		  ft_strcmp.c \
		  ft_strdel.c \
		  ft_strdup.c \
		  ft_strequ.c \
		  ft_striter.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlen.c \
		  ft_strmap.c \
		  ft_strmapi.c \
		  ft_strncat.c \
		  ft_strncmp.c \
		  ft_strncpy.c \
		  ft_strnequ.c \
		  ft_strnew.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strsplit.c \
		  ft_strstr.c \
		  ft_strsub.c \
		  ft_strtrim.c \
		  ft_tolower.c \
		  ft_toupper.c

OBJS	= $(SRCS:.c=.o)

GR		= \033[1;32m
RE		= \033[1;31m
LB		= \033[1;36m
NC		= \033[0m

RM		= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $@ $^
	@echo "$(GR)$(NAME) was created successfully$(NC)"
	@ranlib $@

clean:
	@$(RM) $(OBJS)
	@echo "$(LB)Removed $(NAME) object files$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RE)Removed $(NAME)$(NC)"

re: fclean all

.SILENT: $(OBJS)
