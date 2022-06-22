# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 21:40:40 by ahammam           #+#    #+#              #
#    Updated: 2022/06/22 22:13:03 by ahammam          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= 	philo/main.c \
					philo/utils.c philo/threads.c philo/routine.c				
OBJES 		= ${SRCS:.c=.o}

NAME 		= philoo
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
RM 			= rm -rf

%.o			:	%.c philo.h
				$(CC) ${CFLAGS} -c $< -o $@
	

all			:	$(NAME)

$(NAME)		:	$(LIBFT) $(OBJES) 
				$(CC) $(OBJES) -o $(NAME)
				clear

clean		:
				$(RM) $(OBJES)

fclean		:	clean
				$(RM) philo/$(NAME)

re			:	clean all

.PHONY		:	all clean fclean re