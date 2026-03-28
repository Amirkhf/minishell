# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amary <amary@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/26 09:36:23 by amkhelif          #+#    #+#              #
#    Updated: 2026/03/28 17:31:58 by amary            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes
LIBS = -lreadline

SRC = 	libft/ft_double_str_len.c \
		libft/ft_lstnew_bonus.c \
		libft/ft_lstsize_bonus.c \
		libft/ft_split.c \
		libft/ft_substr.c \
		libft/ft_isalpha.c \
		libft/ft_strdup.c \
		libft/ft_strlen.c \
		libft/ft_strncmp.c \
		libft/ft_expanded_len.c \
		libft/ft_strjoin.c \
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
		srcs/parsing/quote_remove.c \
		srcs/parsing/utils.c \
		srcs/parsing/expander/expander.c \
		srcs/parsing/expander/expander_utils.c \
		srcs/poubelle/poubelle.c \
		srcs/exec/parsing/get_path.c \
		srcs/exec/parsing/build_cmd.c \
		srcs/exec/my_exec.c \
		srcs/exec/built-ins/pwd.c \
		srcs/exec/built-ins/env.c \
		srcs/exec/built-ins/builtins.c \
		srcs/exec/built-ins/unset.c \
		srcs/exec/built-ins/echo.c \
		srcs/exec/built-ins/cd.c \
		srcs/exec/built-ins/exit.c \
		srcs/exec/built-ins/export.c \
		srcs/exec/redirections.c \
		srcs/exec/wait_pid.c \
		srcs/exec/exec_single_builtin.c \
		srcs/exec/signals.c \
		srcs/exec/action_heredoc2.c \
		libft/ft_itoa.c \
		srcs/exec/to_many_arg.c \

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
