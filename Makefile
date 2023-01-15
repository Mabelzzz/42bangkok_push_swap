NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
# MLX_FLAG = -framework OpenGL -framework AppKit -Lmlx -lmlx
HEAD = -Imlx

SRCS = 	check_error.c \
		ft_split.c \
		get_input.c \
		oprt_push.c \
		oprt_rerotate.c \
		oprt_rotate.c \
		oprt_swap.c \
		sort_five.c \
		sort_hundred.c \
		sort_three.c \
		push_swap.c \
		utils_lst.c \
		utils.c \
		sort_100.c \

OBJS = $(SRCS:.c=.o)

%o: %c
	$(CC) $(FLAGS) $(HEAD) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

norm:
	norminette -R checkforbiddensourceheader $(SRCS)
	norminette -R checkdefine so_long.h get_next_line/get_next_line.h

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(OBJS)
	@rm -f push_swap

re:	fclean all

bonus: all

.PHONY:	bonus clean fclean all re
