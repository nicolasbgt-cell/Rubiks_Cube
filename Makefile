NAME = rubiks

CC = gcc -Wall -Wextra -Werror

SRC = /	main.c
	cube_init.c
	display.c
	move.c
	shuflle.c
	slover.c

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
