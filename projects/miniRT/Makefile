CC				= clang
CFLAGS			= -Wall -Wextra -Werror
MAKE			= make

NAME			= miniRT
SRCS			= main.c
OBJS			= $(SRCS:.c=.o)

LIBFT			= libft.a
LIBFTDIR		= ../Libft/

all				: $(NAME)

$(NAME)			: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(addprefix $(LIBFTDIR), $(LIBFT)) -lbsd -lmlx -lXext -lX11 -o $@

$(LIBFT)		:
	make -C $(LIBFTDIR) bonus


clean			:
	rm -f $(OBJS)

fclean			: clean
	rm -f $(NAME)

re				: fclean all



# Tests
test			: CFLAGS = -Wall -Wextra
test			: all
	./$(NAME)

.PHONY			: all clean fclean re test



# %.o: %.c
#     $(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

# $(NAME): $(OBJ)
#     $(CC) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

