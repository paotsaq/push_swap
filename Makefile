HDRS		= includes
CFLAGS 		= -Wall -Wextra -Werror -g
PS_MAIN		= srcs/main.c
SRCS		= srcs/parsing.c \
			  srcs/do_operations.c \
			  srcs/stack_utils.c \
			  srcs/operations.c \
			  srcs/find_lis.c \
			  srcs/lis_utils.c \
			  srcs/utils.c \
			  srcs/push_swap.c \
			  srcs/sort_3_5.c \
			  srcs/sequence_optimizer.c \
			  srcs/algorithm.c \
			  srcs/best_move.c \

CHECKER_SRC = checker_src/checker.c

AR			= ar -rcsv
NAME		= push_swap
OBJS		= ${SRCS:.c=.o}

all: $(NAME)

libft.a:
	$(MAKE) libft.a -C ./libft
	mv ./libft/libft.a ./libft.a

$(NAME): libft.a
	gcc $(CFLAGS) -I $(HDRS) -L. -l ft $(SRCS) $(PS_MAIN) -o push_swap

checker: libft.a
	gcc $(CFLAGS) -I $(HDRS) -L. -l ft $(CHECKER_SRC) $(SRCS) -o checker

clean:
	rm ./push_swap

clean_checker:
	rm ./checker

fclean:
	make fclean -C ./libft
	rm -f $(OBJS)
	rm -f libft.a
	rm -f push_swap
	rm -f checker
	rm -f $(NAME)
	rm -rf ./__.SYMDEF\ SORTED

re: clean all

re_checker: clean_checker checker
