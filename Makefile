# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaoutem- <aaoutem-@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/31 14:14:10 by aaoutem-          #+#    #+#              #
#    Updated: 2023/01/31 14:44:33 by aaoutem-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC=cc
RM=rm -rf
FLAGS= -Wall -Wextra -Werror

SRCS=pipex.c ft_split.c ft_strjoin.c ft_strlen.c ft_strstr.c ft_substr.c \
			utils_fcts.c

SRCS_HEADER=pipex.h

BONUS_SRCS=pipex_bonus.c ft_split.c ft_strjoin.c ft_strlen.c ft_strstr.c \
					get_next_line_bonus.c get_next_line_utils_bonus.c\
					ft_substr.c ft_strcmp.c utils_fcts_bonus.c

BONUS_HEADERS=get_next_line_bonus.h pipex_bonus.h

S_OBJS=$(SRCS:.c=.o)

BONUS_OBJS=$(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(S_OBJS) $(SRCS_HEADER)
	$(CC) $(FLAGS) $(S_OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $< -c

bonus: $(BONUS_OBJS) $(BONUS_HEADERS)
	$(CC) $(FLAGS) $(BONUS_OBJS) -o $(NAME)

clean:
	$(RM) $(S_OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re