# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/26 09:36:23 by amkhelif          #+#    #+#              #
#    Updated: 2026/03/05 14:51:10 by amkhelif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -g3
SRC = srcs/main.c \
		libft/ft_split.c \
		libft/ft_strncmp.c \
		libft/ft_strlen.c \
		libft/ft_lstnew_bonus.c\
		libft/ft_lstsize_bonus.c\
		libft/ft_strdup.c\
		srcs/utils/free.c\
		srcs/lexer/lexer.c\
		srcs/lexer/utils.c\
		srcs/lexer/readline.c\
		srcs/utils/garbage.c\
		srcs/init/init_struct.c\
		srcs/parsing/parsing.c\
		srcs/parsing/error_msg.c\
		srcs/parsing/utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  -lreadline -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
