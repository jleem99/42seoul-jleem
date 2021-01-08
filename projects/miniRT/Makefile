# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 14:15:34 by jleem             #+#    #+#              #
#    Updated: 2021/01/08 15:00:51 by jleem            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= gcc
ERROR_FLAGS		= -Wall -Wextra -Werror
MLX_FLAGS		= -lbsd -lmlx -lXext -lX11
CFLAGS			= $(ERROR_FLAGS) -I$(INCDIR) -I$(LIBFTDIR) -I$(RAYTRACERDIR)includes
MAKE			= make

NAME			= miniRT
SRCDIR			= srcs/
INCDIR			= includes/

SRCS			= $(wildcard $(SRCDIR)*.c)  # explicit (submodules)
OBJS			= $(SRCS:.c=.o)

LIBFT			= $(addprefix $(LIBFTDIR), libft.a)
LIBFTDIR		= ../Libft/

RAYTRACER		= $(addprefix $(RAYTRACERDIR), c-raytracer.a)
RAYTRACERDIR	= c-raytracer/

# Rules
all				: $(NAME)

$(NAME)			: $(OBJS) $(RAYTRACER) $(LIBFT)
	$(CC) $^ $(MLXFLAGS) -o $@ $(CFLAGS) $(MLX_FLAGS) -lm

$(LIBFT)		:
	make -C $(LIBFTDIR) bonus

$(RAYTRACER)	:
	make -C $(RAYTRACERDIR) module

%.o				: %.c
	$(CC) -c $^ -o $@ $(CFLAGS)

# Clean
clean			:
	rm -f $(OBJS)

fclean			: clean
	rm -f $(NAME)

re				: fclean all

# Test
test			: ERROR_FLAGS = -Wall -Wextra
test			: CFLAGS += -O2
# test			: CFLAGS += -g3 -fsanitize=address
test			: fclean all
	rm -f $(RAYTRACERDIR)srcs/*.o
	./$(NAME)

.PHONY			: all clean fclean re test $(LIBFT) $(RAYTRACER)

# %.o: %.c
#     $(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

# $(NAME): $(OBJ)
#     $(CC) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
