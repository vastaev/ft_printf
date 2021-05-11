# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 12:30:03 by cjoanne           #+#    #+#              #
#    Updated: 2021/05/11 19:04:57 by cjoanne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

HEADER	=	ft_printf.h

SRCS	=	srcs/ft_printf.c\
				srcs/ft_parse.c\
				srcs/ft_atoi.c\
				srcs/ft_toprint.c\
				srcs/print_char_strings.c\
				srcs/print_integer_decimal.c\
				srcs/ft_utils.c\
				srcs/print_pointer.c\
				srcs/print_hex.c

OBJS	=	$(SRCS:.c=.o)

CC 		=	gcc

СFLAGS	=	-Wall -Wextra -Werror

INCDIR	=	./includes/

RM		=	rm -f

LIBC    =   ar rcs

all : $(NAME)

%.o : %.c
	$(CC) $(СFLAGS) -I $(INCDIR) -c $< -o $@

$(NAME) : $(OBJS) $(INCDIR)$(HEADER)
	$(LIBC) $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re