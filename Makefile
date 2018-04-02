#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iyerin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 14:35:52 by iyerin            #+#    #+#              #
#    Updated: 2017/12/14 14:35:53 by iyerin           ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = get_next_line


all:
	gcc -g -o $(NAME) get_next_line.c libft/libft.a && ./get_next_line

# clean:
# 	rm -f libft/*.o

fclean: 
	rm -f  $(NAME)

re:	fclean all
