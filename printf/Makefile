# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: greita <greita@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 12:22:32 by greita            #+#    #+#              #
#    Updated: 2021/12/13 19:10:42 by greita           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libftprintf.a

SRC = 		ft_printf.c \
			ft_printf_utils.c \
			ft_print_csp.c \
			ft_print_diux.c

OBJ = 		$(SRC:.c=.o)

CC =		gcc

FLAGS =		-Wall -Wextra -Werror -O2

D_FILES =	$(SRC:.c=.d)

%.o :		%.c
	$(CC) $(FLAGS) -c $< -o $@ -MMD

all :		$(NAME)

-include	$(D_FILES)

$(NAME) :	$(OBJ)
	make all -C ./libft
	cp ./libft/libft.a $(NAME)
	ar rcs $(NAME) $?

clean :
	make clean -C ./libft
	rm -f $(OBJ) $(D_FILES)

fclean :	clean
	rm -f $(NAME) ./libft/libft.a

re :		fclean all

bonus:		all

.PHONY :	all clean fclean re bonus
