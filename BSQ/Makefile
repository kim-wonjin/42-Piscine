# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wokim <wokim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/13 16:33:36 by wokim             #+#    #+#              #
#    Updated: 2021/04/13 19:16:38 by wokim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = srcs/main.c srcs/utility.c srcs/read.c \
	srcs/algorithm.c srcs/get_condition.c srcs/print.c

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -O3 -o $(NAME) $(SRC)
clean:
		/bin/rm -f
fclean: clean
		/bin/rm -f $(NAME)
re: fclean all
