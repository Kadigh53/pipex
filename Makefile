# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/31 14:14:10 by aaoutem-          #+#    #+#              #
#    Updated: 2023/01/29 14:12:35 by aaoutem-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := pipex
CC        := cc
FLAGS    := -Wall -Wextra -Werror 
SRCS        :=      pipex.c ft_split.c ft_strjoin.c ft_strlen.c ft_strstr.c \
							ft_substr.c utils_fcts.c \
						  
OBJS        := $(SRCS:.c=.o)

.c.o:
	 @ ${CC} ${FLAGS} -c $< -o ${<:.c=.o}
	 @ echo "Making..."

RM		    := rm -f

${NAME}:	${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

bonus:		all

clean:
			@ ${RM} ${OBJS}
		
fclean:		clean
			@ ${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re


