# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/20 13:23:46 by lowatell          #+#    #+#              #
#    Updated: 2025/01/25 15:26:15 by lowatell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror -DPATH=\"$(PATH)\"
RM = rm -rf

SRC_DIR = srcs
INCS_DIR = incs
OBJS_DIR = objs

NAME = pipex

SRCS =	main.c parsing.c

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

GREEN = \033[32m

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS_DIR)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@make clean -C libft --no-print-directory
	@$(RM) $(OBJS_DIR)
	@echo "$(GREEN)Objects files have been deleted."

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)$(NAME) has been deleted."

re: fclean all

$(NAME): $(OBJS)
	@make -C libft/ --no-print-directory
	@mv libft/libft.a $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(OBJS_DIR)/libft.a -o $(NAME)
	@echo "$(GREEN)$(NAME) has been compiled."

.PHONY: all clean fclean re

