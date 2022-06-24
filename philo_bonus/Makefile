# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 21:40:40 by ahammam           #+#    #+#              #
#    Updated: 2022/06/24 12:13:09 by ahammam          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_B		=   main.c
OBJES_B 	=   ${SRCS_B:.c=.o}

NAME_B 		=   philo_bonus
CC 			=   cc
CFLAGS 		=   -Wall -Wextra -Werror
RM 			=   rm -rf

%.o			:	%.c philo_bonus.h
				$(CC) ${CFLAGS} -c $< -o $@
	

all			:	$(NAME_B)

$(NAME_B)	:	$(OBJES_B) 
				$(CC) $(OBJES_B) -o $(NAME_B)
				clear

bonus		: 	$(NAME_B)

clean		:
				$(RM) $(OBJES_B)

fclean		:	clean
				$(RM) $(NAME_B)

re			:	clean all

.PHONY		:	all clean fclean re bonus