NAME = push_swap

NAME_BONUS = checker

LIBFT_NAME = libft.a

SRCS = $(wildcard *.c)

SRCS_BONUS = $(filter-out main.c, $(wildcard *.c)) $(wildcard bonus/*.c)

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${SRCS}
	make -C libft/
	cc $(CFLAGS) $^ -o $@ -L./libft -lft

bonus: ${SRCS_BONUS}
	make -C libft/
	cc $(CFLAGS) $^ -o $(NAME_BONUS) -L./libft -lft

clean:
	make clean -C libft

fclean: clean
	rm -f ${NAME} ${NAME_BONUS}
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus
