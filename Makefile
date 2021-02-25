# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/20 12:51:52 by abourdar          #+#    #+#              #
#    Updated: 2020/12/23 11:33:44 by abourdar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_chek.c ft_print_int.c ft_print_p.c ft_print_pourcent.c\
	 	ft_print_s.c ft_print_u.c ft_print_width.c ft_print_x.c ft_printf.c ft_setup_flags.c\
		 ft_print_utils.c ft_itoa_p.c\
		 libprintf/ft_itoa.c libprintf/ft_isdigit.c libprintf/ft_putchar_fd.c\
		 libprintf/ft_putstr_fd.c libprintf/ft_strdup.c libprintf/ft_strjoin.c\
		 libprintf/ft_strlen.c libprintf/ft_substr.c

OBJS = ${SRCS:.c=.o}

CC		= clang
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
