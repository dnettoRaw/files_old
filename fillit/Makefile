# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/24 18:03:09 by abeauvoi          #+#    #+#              #
#    Updated: 2017/05/10 16:41:26 by abeauvoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit

CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.c \
			  ft_check_buf_1.c \
			  ft_check_buf_2.c \
			  parsing.c \
			  ft_int_tab_cmp.c \
			  map_functions.c \
			  ft_resolve.c \
			  stats.c \
			  list_functions.c

OBJS		= $(SRCS:.c=.o)

LIB_PATH	= libft
LDFLAGS		= -L./$(LIB_PATH) -lft

INCS		= -I./$(LIB_PATH)

RM			= rm -f

MAKE_LIB	= make -C $(LIB_PATH)

# Colors

GREEN		= "\033[1;32m"
RED			= "\033[1;31m"
LBLUE		= "\033[1;36m"
NC			= "\033[0m"

# Messages

DO_MSG		= $(GREEN)"Done"$(NC)
CL_MSG		= $(LBLUE)"Removed $(NAME) object files"$(NC)
LK_MSG		= "Linking"
RM_MSG		= $(RED)"Removed $(NAME)"$(NC)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE_LIB)
	@$(CC) -o $@ $^ $(LDFLAGS)
	@echo "Compiling" [ $@ ] $(DO_MSG)

%.o: %.c $(LIB_PATH)/*.h
	@$(CC) $(INCS) $(CFLAGS) -c -o $@ $<
	@echo $(LK_MSG) [ $< ] $(DO_MSG)

clean:
	@$(MAKE_LIB) clean
	@$(RM) $(OBJS)
	@echo $(CL_MSG)

fclean: clean
	@$(MAKE_LIB) fclean
	@$(RM) $(NAME)
	@echo $(RM_MSG)

re: fclean all
