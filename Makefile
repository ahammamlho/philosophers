# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 21:40:40 by ahammam           #+#    #+#              #
#    Updated: 2022/06/22 22:59:18 by ahammam          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=   philo/main.c philo/utils.c philo/threads.c philo/routine.c				
OBJES 		=   ${SRCS:.c=.o}
SRCS_B		=   philo_bonus/main.c
OBJES_B 	=   ${SRCS_B:.c=.o}

NAME 		=   philoo
NAME_B 		=   philo_bonuss
CC 			=   cc
CFLAGS 		=   -Wall -Wextra -Werror
RM 			=   rm -rf

%.o			:	%.c philo.h
				$(CC) ${CFLAGS} -c $< -o $@
	

all			:	$(NAME)

$(NAME)		:	$(OBJES) 
				$(CC) $(OBJES) -o $(NAME)
				clear

$(NAME_B)	:	$(OBJES_B) 
				$(CC) $(OBJES_B) -o $(NAME_B)
				clear

bonus		: 	$(NAME_B)

clean		:
				$(RM) $(OBJES) $(OBJES_B)

fclean		:	clean
				$(RM) $(NAME) $(NAME_B)

re			:	clean all

.PHONY		:	all clean fclean re