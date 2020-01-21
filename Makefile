# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/23 16:32:09 by hmoumani          #+#    #+#              #
#    Updated: 2020/01/21 20:15:57 by hmoumani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_atoi.c ft_putchar_fd.c ft_flags.c\
	ft_strdup.c ft_tolower.c ft_getmax.c\
	ft_toupper.c ft_calloc.c ft_strrev.c\
	ft_putnbr_fd.c ft_strchr.c ft_abs.c\
	ft_itoa.c ft_putstr_fd.c ft_printp.c ft_prints.c \
	ft_isalpha.c ft_printu.c ft_printc.c ft_printd.c \
	ft_strlen.c ft_printf.c ft_collect_data.c ft_printx.c

OBJ = ft_atoi.o ft_putchar_fd.o ft_flags.o\
	ft_strdup.o ft_tolower.o ft_getmax.o\
	ft_toupper.o ft_calloc.o ft_strrev.o\
	ft_putnbr_fd.o ft_strchr.o ft_abs.o\
	ft_itoa.o ft_putstr_fd.o ft_printp.o  ft_prints.o \
	ft_isalpha.o ft_printu.o ft_printc.o ft_printd.o \
	ft_strlen.o ft_printf.o ft_collect_data.o ft_printx.o

all : $(NAME)

$(NAME) :
	gcc $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ) && ranlib $(NAME)

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : clean fclean all


.PHONY : clean fclean all