CC = clang
CFLAGS = -Wall -Wextra -g3 -fsanitize=undefined -MMD

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: a.out

a.out: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) main.c -o $@

bonus: b.out

clean:
	rm -f *.o *.d

fclean: clean
	rm -f *.out

re: fclean all

-include $(DEPS)

.PHONY: all bonus clean fclean re
