# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amkhelif <amkhelif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/26 09:36:23 by amkhelif          #+#    #+#              #
#    Updated: 2026/03/09 16:30:06 by amkhelif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -g3 -Wall -Wextra
INCLUDES = -I./includes
LIBS = -lreadline

SRC = 	libft/ft_double_str_len.c \
		libft/ft_lstnew_bonus.c \
		libft/ft_lstsize_bonus.c \
		libft/ft_split.c \
		libft/ft_substr.c \
		libft/ft_strdup.c \
		libft/ft_strlen.c \
		libft/ft_strncmp.c \
		srcs/error/error_msg.c \
		srcs/init/init_struct.c \
		srcs/init/extract_path.c \
		srcs/lexer/lexer.c \
		srcs/lexer/utils_lexer.c \
		srcs/main/main.c \
		srcs/main/readline.c \
		srcs/memory/free.c \
		srcs/memory/garbage.c \
		srcs/parsing/parsing.c \
		srcs/parsing/utils.c \
		srcs/poubelle/poubelle.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re