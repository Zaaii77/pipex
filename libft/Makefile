# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/20 13:23:46 by lowatell          #+#    #+#              #
#    Updated: 2025/01/03 16:12:25 by lowatell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

SRC_DIR = srcs
PRINTF_DIR = $(addprefix $(SRC_DIR)/, printf)
GNL_DIR = $(addprefix $(SRC_DIR)/, get_next_line)
INCS_DIR = incs

NAME = libft.a

SRCS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_atol.c free_tab.c \

OBJS = $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_OBJS = $(addprefix $(SRC_DIR)/, $(BONUS:.c=.o))

PRINTF = ft_putptr.c ft_print_address.c ft_printf.c ft_putchar.c \
		 ft_putstr.c ft_putnbr.c ft_nbr_len.c

OBJS_PRINTF = $(addprefix $(PRINTF_DIR)/, $(PRINTF:.c=.o))

GNL = get_next_line.c get_next_line_utils.c \

GNL_OBJS = $(addprefix $(GNL_DIR)/, $(GNL:.c=.o))

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS_DIR)

GREEN = \033[32m

all: $(NAME)

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS) $(OBJS_PRINTF) $(GNL_OBJS)
	@echo "$(GREEN)libft objects have been deleted."

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)libft.a has been deleted."

re: fclean all

$(NAME): $(OBJS) $(BONUS_OBJS) $(OBJS_PRINTF) $(GNL_OBJS)
	@$(AR) $(NAME) $(OBJS) $(BONUS_OBJS) $(OBJS_PRINTF) $(GNL_OBJS)
	@echo "$(GREEN)libft.a has been compiled."

.PHONY: all clean fclean re bonus
