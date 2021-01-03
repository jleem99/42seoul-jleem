CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I$(INCDIR) $(LIBFTFLAGS)
LIBFTFLAGS		= -I$(LIBFTDIR)includes -L$(LIBFTDIR) -lft
MLXFLAGS		= -lbsd -lmlx -lXext -lX11 
MAKE			= make

NAME			= miniRT
SRCDIR			= srcs/
INCDIR			= includes/

SRCS_			= main.c
SRCS			= $(addprefix $(SRCDIR), $(SRCS_))
OBJS			= $(SRCS:.c=.o)

LIBFT			= $(addprefix $(LIBFTDIR), libft.a)
LIBFTDIR		= ../Libft/

# Rules
all				: $(NAME)

$(NAME)			: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $@

$(LIBFT)		:
	make -C $(LIBFTDIR) bonus

%.o				: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

# Clean
clean			:
	rm -f $(OBJS)

fclean			: clean
	rm -f $(NAME)

re				: fclean all

# Test
test			: CFLAGS = -Wall -Wextra -I$(INCDIR) $(LIBFTFLAGS)
test			: all
	./$(NAME)

.PHONY			: all clean fclean re test



# %.o: %.c
#     $(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

# $(NAME): $(OBJ)
#     $(CC) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

