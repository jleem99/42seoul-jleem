# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/31 10:43:39 by jleem             #+#    #+#              #
#    Updated: 2020/12/31 13:09:26 by jleem            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BUFFER_SIZE	= 5

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE) 

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
