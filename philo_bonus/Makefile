# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahammam <ahammam@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 21:40:40 by ahammam           #+#    #+#              #
#    Updated: 2022/06/24 16:47:37 by ahammam          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_B		=   philo_bonus.c utils_bonus.c processes.c actions_bonus.c
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