# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleem <jleem@students.42seoul.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/24 21:00:24 by jleem             #+#    #+#              #
#    Updated: 2020/12/30 23:23:15 by jleem            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

AR			= ar -rcs
RM			= rm -f

NAME		= libft.a

INCDIR		= includes/
SRCDIR		= srcs/

SRCS_P1_	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c
SRCS_P2_	= ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCS_BONUS_	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRCS_P1		= $(addprefix $(SRCDIR), $(SRCS_P1_))
SRCS_P2		= $(addprefix $(SRCDIR), $(SRCS_P2_))
SRCS_BONUS	= $(addprefix $(SRCDIR), $(SRCS_BONUS_))

OBJS_P1		= $(SRCS_P1:.c=.o)
OBJS_P2		= $(SRCS_P2:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all			: $(NAME)

$(NAME)		: $(OBJS_P1) $(OBJS_P2)
	$(AR) $@ $^

%.o			: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I$(INCDIR)

clean		:
	$(RM) $(OBJS_P1) $(OBJS_P2) $(OBJS_BONUS)

fclean		: clean
	$(RM) $(NAME)

bonus		: $(OBJS_P1) $(OBJS_P2) $(OBJS_BONUS)
	$(AR) $(NAME) $^

re			: fclean all

.PHONY		: all clean fclean re bonus
