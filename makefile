NAME = philo

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

SOURCE = main.c check_error.c utils.c init.c action.c

OBJS = $(SOURCE:.c=.o)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean :
		rm -f $(OBJS)

fclean: clean
		    rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all