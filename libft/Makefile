# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/07 16:01:35 by cdeniau           #+#    #+#              #
#    Updated: 2016/10/15 17:47:03 by cdeniau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       = libft.a
ALL_CFLAGS = -Wall -Wextra -Werror -g
CC         = gcc
RM		   = rm -rf

SRCS_DIR   = srcs
OBJS_DIR   = objs
INCS_DIR   = incs
S		   = ft_errno.c						\
			 ft_itoa.c						\
			 ft_strlen.c					\
			 ft_putstr.c					\
			 ft_putendl.c					\
			 ft_print_hex.c					\
			 ft_memset.c					\
			 ft_arr_sort.c					\
			 ft_strcmp.c					\
			 ft_memcmp.c					\
			 ft_arr_sort.c					\
			 ft_strdup.c					\

SRCS	   = $(addprefix $(SRCS_DIR)/, $S)
OBJS       = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creating libft"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Done"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(ALL_CFLAGS) -I $(INCS_DIR) -c $< -o $@
	@echo "\033[A\033[K\033[A"

clean:
	@$(RM) $(OBJS)	
	@echo "Objs repository cleaned"

fclean: clean
	@$(RM) $(NAME)
	@echo "Libft repository cleaned"

re: fclean all

$(OBJS): | $(OBJS_DIR)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)
