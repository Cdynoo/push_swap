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

B_NAME = checker_Mac

LIBFT_DIR = ./libft

LIBFT = ./libft/libft.a

INCLUDE = -L $(LIBFT_DIR) -lft

CC = cc

CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_DIR)

SOURCE  =  list_building.c \
		   dc_list_manipulation.c \
		   dc_moves.c \
		   dc_rotations.c \
		   list.c \
		   utils.c \
		   dc_cost.c \
		   dc_optimalmoves.c \
		   dc_turk_sort.c \
		   process_input.c \
		   main.c 

B_SOURCE  =	dc_list_manipulation_bonus.c \
			dc_moves_bonus.c \
			dc_rotations_bonus.c \
			list_bonus.c \
			list_building_bonus.c \
			dc_testsort_bonus.c \
			dc_checker_bonus.c \
			main_bonus.c 

OBJS    = $(SOURCE:.c=.o)

B_OBJS    = $(B_SOURCE:.c=.o)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME) ${INCLUDE}

$(B_NAME): $(LIBFT) $(B_OBJS)
	$(CC) $(CFLAGS)  $(B_OBJS) -o $(B_NAME) ${INCLUDE}

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

norm:
	norminette $(SOURCE) $(B_SOURCE)

all: $(NAME) $(B_NAME)

bonus: $(B_NAME)

clean:
	@rm -f $(OBJS) $(B_OBJS)
	@cd $(LIBFT_DIR) && $(MAKE) clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(B_NAME)
	@cd $(LIBFT_DIR) && $(MAKE) fclean

re: fclean all
