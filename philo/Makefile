# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 21:40:40 by ahammam           #+#    #+#              #
#    Updated: 2022/06/24 12:13:20 by ahammam          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=   main.c utils.c threads.c routine.c				
OBJES 		=   ${SRCS:.c=.o}

NAME 		=   philo
CC 			=   cc
CFLAGS 		=   -Wall -Wextra -Werror
RM 			=   rm -rf

%.o			:	%.c philo.h
				$(CC) ${CFLAGS} -c $< -o $@
	

all			:	$(NAME)

$(NAME)		:	$(OBJES) 
				$(CC) $(OBJES) -o $(NAME)
				clear

clean		:
				$(RM) $(OBJES)

fclean		:	clean
				$(RM) $(NAME)

re			:	clean all

.PHONY		:	all clean fclean re