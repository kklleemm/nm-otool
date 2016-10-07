# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/07 16:01:35 by cdeniau           #+#    #+#              #
#    Updated: 2016/10/07 17:13:50 by cdeniau          ###   ########.fr        #
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
			 ft_strlen.c

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
	@echo "Compilation"

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
