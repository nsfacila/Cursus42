# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noelsanc <noelsanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 17:31:17 by noelsanc          #+#    #+#              #
#    Updated: 2024/05/19 21:38:06 by noelsanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = \
ft_atoi.c\
ft_bzero.c\
ft_calloc.c\
ft_isalpha.c\
ft_isalnum.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_itoa.c\
ft_lstnew.c\
ft_strmapi.c\
ft_memchr.c\
ft_memmove.c\
ft_memset.c\
ft_memcpy.c\
ft_putchar_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_putstr_fd.c\
ft_split.c\
ft_strlen.c\
ft_strncmp.c\
ft_strlcpy.c\
ft_strlcat.c\
ft_strchr.c\
ft_strrchr.c\
ft_strnstr.c\
ft_substr.c\
ft_striteri.c\
ft_strjoin.c\
ft_strdup.c\
ft_tolower.c\
ft_toupper.c\



OBJS = $(SRC:.c=.o)

all:  $(NAME)

$(NAME):$(OBJS)
	ar rcs $(NAME) $(OBJS)
	
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: fclean clean all re

