# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estepere <estepere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 12:32:11 by estepere          #+#    #+#              #
#    Updated: 2024/10/10 12:32:12 by estepere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

SOURCE = main.c check_error.c utils.c init.c action.c death.c

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