# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olmohame <olmohame@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 23:38:10 by olmohame          #+#    #+#              #
#    Updated: 2024/01/02 23:38:12 by olmohame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

#FLAGS = -Wall -Wextra -Werror

SOURCE  =  list_building.c \
		   list_manipulation.c \
		   moves.c \
		   rotations.c \
		   utils.c \
		   streak.c \
		   dc_init.c  \
		   dc_movenode.c \
		   dc_optimalmoves.c \
		   sort.c \
		   main.c

OBJS    = $(SOURCE:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SOURCE) -o $(NAME)

norm:
	norminette $(SOURCE)

all: $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
