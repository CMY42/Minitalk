# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 12:56:43 by cmansey           #+#    #+#              #
#    Updated: 2023/01/14 12:56:43 by cmansey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SRCS = client.c server.c

all: $(NAME)

OBJS = $(SRCS:.c=.o)

LIBFT = libft

CC = gcc
RM = rm -f
AR = ar -rcs

CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	@$(RM) -f $(LIBFT)/libft.a

re: fclean all

.PHONY: all clean fclean re
