# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 19:22:40 by hluiz-ma          #+#    #+#              #
#    Updated: 2024/09/11 20:34:03 by hluiz-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project settings
NAME = push_swap
B_NAME = bonus_push_swap
CC = cc #-fsanitize=address
CFLAGS = -Wall -Wextra -Werror -g
IFLAGS = -I./include 
RM = rm -rf

# Paths
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS_DIR = ./src
SRCS_BONUS = ./bonus

# Source files
SRCS = $(SRCS_DIR)/main.c \
		$(SRCS_DIR)/utils.c \
		$(SRCS_DIR)/stack_init.c \
		$(SRCS_DIR)/stack_utils.c \
		$(SRCS_DIR)/start_list.c \
		$(SRCS_DIR)/error_free.c \
		$(SRCS_DIR)/push.c \
		$(SRCS_DIR)/swap.c \
		$(SRCS_DIR)/rotate.c \
		$(SRCS_DIR)/reverse_rotate.c \
		$(SRCS_DIR)/sort.c \
		$(SRCS_DIR)/check_nodes.c \
		$(SRCS_DIR)/push_swap.c \
		$(SRCS_DIR)/push_swap_sort.c \
		
BONUS = $(SRCS_BONUS)/main_bonus.c \
		$(SRCS_DIR)/utils.c \
		$(SRCS_DIR)/stack_init.c \
		$(SRCS_DIR)/stack_utils.c \
		$(SRCS_DIR)/start_list.c \
		$(SRCS_DIR)/error_free.c \
		$(SRCS_DIR)/push.c \
		$(SRCS_DIR)/swap.c \
		$(SRCS_DIR)/rotate.c \
		$(SRCS_DIR)/reverse_rotate.c \
		$(SRCS_DIR)/sort.c \
		$(SRCS_DIR)/check_nodes.c \
		$(SRCS_DIR)/push_swap.c \
		$(SRCS_DIR)/push_swap_sort.c \
		$(SRCS_BONUS)/checker.c \

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(BONUS:.c=.o)

# Default target
all: $(MLX) $(NAME)

# Linking the final executable
$(NAME):	$(SRCS) $(LIBFT) $(OBJS)
			@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LIBFT) -o $(NAME)  
			@echo "\033[1;32m[ ✔ ] $(NAME) ready!\033[0m"
			@echo "\033[0;31m𓄿 𓅓  Made by Alabar 𓄿 𓅓"

# Building the bonus executable
bonus: $(B_NAME)

$(B_NAME): $(OBJS_BONUS) $(LIBFT)
			@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(B_NAME)
			@echo "\033[1;32m[ ✔ ] $(B_NAME) ready!\033[0m"
			@echo "\033[0;31m𓄿 𓅓  Made by Alabar 𓄿 𓅓"
						
# Building the libft library			
$(LIBFT):
			@make --silent -C $(LIBFT_DIR)			
			

# Compiling object files
%.o: %.c 
			@$(CC) $(CFLAGS) -c $^ -o $@
			@echo "\033[90m[\033[32mOK\033[90m]\033[34m Compiling $<\033[0m"

# Cleaning object files
clean:
			@$(RM) $(OBJS) $(OBJS_BONUS)
			@$(RM) $(SRCS_DIR)/*.o
			@$(RM) $(SRCS_BONUS)/*.o
			@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Object files deleted\033[0m"

# Full cleanup
fclean:		clean
			@$(RM) $(NAME) $(B_NAME) $(MLX_DIR)
			@make fclean -C $(LIBFT_DIR)
			@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Executable and Minilibx deleted.\033[0m"

# Rebuild everything
re: 		fclean all

						
.PHONY:		all clean fclean re bonus