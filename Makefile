CC = clang
CFLAGS = -Wall -Wextra -g3 -fsanitize=address,undefined -MMD

SRCS = get_next_line.c get_next_line_utils.c
INCS = get_next_line.h
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: a.out

a.out: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) main.c -o $@

bonus: b.out

norm: $(SRCS) $(INCS)
	norminette $^

clean:
	rm -f *.o *.d

fclean: clean
	rm -f *.out

re: fclean all

-include $(DEPS)

.PHONY: all bonus clean fclean re
