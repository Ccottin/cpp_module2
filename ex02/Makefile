# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccottin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 12:16:24 by ccottin           #+#    #+#              #
#    Updated: 2022/10/01 03:21:04 by ccottin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= illuminatedNumbers

SRCS	= main.cpp Fixed.cpp

CC	= c++

OBJS	= $(SRCS:.cpp=.o)

CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g3

all	:	$(NAME)

%.o	:	%.cpp
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $@

clean	:
		rm -rf $(OBJS)

fclean	:	clean
		rm -rf $(NAME)

re	:	fclean
		make

.PHONY	:	all fclean clean re
