# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 12:56:43 by cmansey           #+#    #+#              #
#    Updated: 2023/01/16 11:20:50 by cmansey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= client.c server.c

OBJS	:= $(SRCS:%.c=%.o)

NAME	= minitalk

CC		= gcc
RM		= rm -f

CFLAGS 	= -Wall -Wextra -Werror

all:		${NAME}

%.o:	%.c
		${CC} ${CFLAGS} -Ilibft -c $? -o $@

${NAME}:	 server client

server:		server.o
		@make -C libft
		${CC} ${CFLAGS} $? -Llibft -lft -o server

client:		client.o
		@make -C libft
		${CC} ${CFLAGS} $? -Llibft -lft  -o client

libft:
		make -C libft

clean:
			make clean -C libft
			${RM} ${OBJS}

fclean:		clean
			${RM} server client

re:			fclean all

.PHONY:		libft
