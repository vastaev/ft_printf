# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 12:30:03 by cjoanne           #+#    #+#              #
#    Updated: 2021/04/29 23:46:43 by cjoanne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

HEADER	=	ft_printf.h

SRCS	=	ft_printf.c\
				srcs/ft_parse.c

OBJS	=	$(SRCS:.c=.o)

CC 		=	gcc

FLAGS	=	-Wall -Wextra -Werror -O2

INCLUDE	=	-I./includes

RM		=	rm -f

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(HEADER)
	@cd libft && MAKE
	@cp libft/libft.a $(NAME)
	$(LIBC) $(NAME) $(OBJS) $?

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re