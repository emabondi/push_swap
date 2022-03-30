# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 17:54:22 by ebondi            #+#    #+#              #
#    Updated: 2022/03/30 17:54:22 by ebondi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker

SRC = main.c start.c first_moves.c ft_split.c moves.c moves_2.c push_swap.c utils.c utils_2.c utils_3.c
SRC_CHECKER = checker.c checker_utils.c moves.c moves_2.c utils.c utils_2.c utils_3.c get_next_line.c get_next_line_utility.c ft_split.c start.c first_moves.c

FLG = -Wall -Werror -Wextra 

$(NAME):
		gcc $(FLG) $(SRC) -o $(NAME)

bonus:
		gcc $(FLG) $(SRC_CHECKER) -o $(CHECKER) -D BUFFER_SIZE=42

all: 	bonus $(NAME)

clean:
		rm -f $(NAME)
		rm -f $(CHECKER)

fclean:	clean

re: 	fclean all

.PHONY:	all clean fclean re