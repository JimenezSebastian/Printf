# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almejia- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 06:18:09 by almejia-          #+#    #+#              #
#    Updated: 2024/09/12 15:53:51 by almejia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror 
AR = ar rcs

SOURCES = src/ft_printf.c \

OBJ = $(SOURCES:.c=.o)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

all: $(NAME)

.PHONY: all clean fclean re

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
