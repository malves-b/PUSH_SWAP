# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malves-b <malves-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 11:33:04 by malves-b          #+#    #+#              #
#    Updated: 2024/11/04 12:15:58 by malves-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = push_swap

FILES = $(wildcard srcs/*.c libft/*.c ft_printf/*.c operations/*.c)

OBJS = $(FILES:.c=.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g
RM	= rm -f

GREEN = \033[1;32m
BROWN = \033[1;33m
RESET = \033[0m

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	@echo "$(GREEN)COMPILED$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "$(BROWN)OBJS REMOVED$(RESET)"

fclean: clean
	@$(RM) $(LIBRARY) $(TARGET)
	@echo "$(BROWN)EXE REMOVED$(RESET)"

re: fclean all

.PHONY: all, clean, fclean, re
