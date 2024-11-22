# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 15:01:43 by jarumuga          #+#    #+#              #
#    Updated: 2024/07/30 22:43:10 by jarumuga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -I./libft/includes -Wall -Wextra -Werror
LDFLAGS = -L./libft -lft
INCLUDES = -I includes
SRCS_DIR = srcs
OBJS_DIR = objs
SRCS =  $(SRCS_DIR)/errors.c \
        $(SRCS_DIR)/free.c \
        $(SRCS_DIR)/init.c \
        $(SRCS_DIR)/operation.c \
        $(SRCS_DIR)/push_swap.c \
        $(SRCS_DIR)/push.c \
        $(SRCS_DIR)/radix.c \
        $(SRCS_DIR)/rotate.c \
        $(SRCS_DIR)/rrotate.c \
        $(SRCS_DIR)/sort.c \
        $(SRCS_DIR)/swap.c \
        $(SRCS_DIR)/utils.c
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

libft/libft.a:
	$(MAKE) -C libft

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
