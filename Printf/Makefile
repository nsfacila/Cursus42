# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/29 19:29:35 by noelsanc          #+#    #+#              #
#    Updated: 2024/05/30 22:18:16 by noelsanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

CC = clang

SRC = \
	ft_printf.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_puthexa.c \
	ft_putptr.c \
	ft_putunsigned.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -c $(SRC)
	ar rcs $(NAME)	$(OBJ)

%.o :%.c
	$(CC) $(FLAGS)	-c $< -o $@


clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY : all clean fclean re