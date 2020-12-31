# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/31 10:43:39 by jleem             #+#    #+#              #
#    Updated: 2020/12/31 16:31:42 by jleem            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUFFER_SIZE	= 3

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE)
CFLAGS		+= -g
# CFLAGS		+= -fsanitize=address

SRCS		= get_next_line.c get_next_line_utils.c
OBJS		= $(SRCS:.c=.o)


NAME		= readline

all			: $(NAME)

$(NAME)		: $(OBJS)
	$(CC) $(CFLAGS) main.c $(OBJS) -o $@

%.o			: %.c
	$(CC) $(CFLAGS) -c $^

clean		:
	rm -f $(OBJS)

fclean		: clean
	rm -f $(NAME)

re			: fclean all

.PHONY		: all clean fclean re
