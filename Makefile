HDRS		= includes
CFLAGS 		= -Wall -Wextra -Werror -g
SRCS		= $(wildcard ./srcs/*.c)
AR			= ar -rcsv
NAME		= push_swap

all: $(NAME)

libft.a:
	$(MAKE) libft.a -C ./libft
	mv ./libft/libft.a ./libft.a

$(NAME): libft.a
	gcc $(CFLAGS) -I $(HDRS) -L. -l ft $(SRCS) -o push_swap

clean:
	rm ./push_swap

fclean: clean
	make fclean -C ./libft
	rm -f $(OBJS)
	rm -f libft.a
	rm -f $(NAME)
	rm -rf ./__.SYMDEF\ SORTED

re: clean all

