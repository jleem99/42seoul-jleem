# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 14:15:34 by jleem             #+#    #+#              #
#    Updated: 2021/01/11 01:22:51 by jleem            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= clang
ERROR_FLAGS		= -Wall -Wextra -Werror
MLX_FLAGS		= -lbsd -lmlx -lXext -lX11
INC_FLAGS		= -I$(INCDIR) -I$(LIBFTDIR) -I$(RAYTRACERDIR)includes
CFLAGS			= $(ERROR_FLAGS) $(INC_FLAGS)

NAME			= miniRT
SRCDIR			= srcs/
INCDIR			= includes/

SRCS			= $(wildcard $(SRCDIR)*.c)  # explicit (submodules)
OBJS			= $(SRCS:.c=.o)

LIBFT			= $(addprefix $(LIBFTDIR), libft.a)
LIBFTDIR		= ../Libft/

RAYTRACER		= $(addprefix $(RAYTRACERDIR), c-raytracer.a)
RAYTRACERDIR	= c-raytracer/

all				: $(NAME)

$(NAME)			: $(OBJS) $(RAYTRACER) $(LIBFT)
	$(CC) $^ $(MLXFLAGS) -o $@ $(CFLAGS) $(MLX_FLAGS) -lm

$(LIBFT)		:
	$(MAKE) -C $(LIBFTDIR) CC=clang CFLAGS=-O3 bonus

$(RAYTRACER)	:
	$(MAKE) -C $(RAYTRACERDIR) module

clean			:
	$(MAKE) -C $(RAYTRACERDIR) clean
	$(MAKE) -C $(LIBFTDIR) clean
	rm -f $(OBJS)

fclean			: clean
	$(MAKE) -C $(RAYTRACERDIR) fclean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re				: fclean all

run				: all
	./$(NAME)

test			: ERROR_FLAGS = -Wall -Wextra
test			: CFLAGS += -O3
# test			: CFLAGS += -g3 -pg
# test			: CFLAGS += -g3
# test			: CFLAGS += -g3 -fsanitize=address
test			: run

prof			: test
	gprof ./$(NAME)

.PHONY			: all clean fclean re test $(LIBFT) $(RAYTRACER) prof

# %.o: %.c
#     $(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

# $(NAME): $(OBJ)
#     $(CC) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
