# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 11:42:32 by akunegel          #+#    #+#              #
#    Updated: 2024/08/15 14:29:11 by akunegel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Cub3d

CC		= gcc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

.PHONY: all clean re

all: $(NAME)

$(NAME):
	@printf "$(CURSIVE)$(GRAY) 	- Compiling $(NAME)... $(RESET)\n"
	@ $(CC) $(FLAGS) main.c gnl/get_next_line.c gnl/get_next_line_utils.c parsing/get_data.c parsing/get_data_s.c parsing/get_data_t.c parsing/get_file.c parsing/get_map.c parsing/check_map.c parsing/check_textures.c utils/ft_split.c utils/utils.c utils/utils2.c -o $(NAME)
	@printf "$(GREEN)    - Executable ready.\n$(RESET)"

clean:
	@$(RM) $(NAME)
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

fclean:
	@$(RM) $(NAME)
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re: clean all
