NAME			= Cub3d

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

CC 				= gcc -fsanitize=address -static-libasan

STANDARD_FLAGS 	= -Wall -Wextra -Werror

REMOVE 			= rm -f

SRCS 			= 	srcs/main.c							\
					srcs/utils/ft_exit.c				\
					srcs/utils/utils.c					\
					srcs/utils/utils2.c					\
					srcs/utils/ft_split.c				\
					includes/gnl/get_next_line_utils.c	\
					includes/gnl/get_next_line.c		\
					srcs/parsing/parsing.c				\
					srcs/parsing/get_file.c				\
					srcs/parsing/get_paths.c			\
					srcs/parsing/get_t_paths.c			\
					srcs/parsing/paths_checks.c			\
					srcs/parsing/check_rgb.c			\
					srcs/parsing/get_map.c				\
					srcs/parsing/check_map.c

all:			${NAME}

${NAME}:
				@${CC} ${SRCS} ${LIBFT} ${STANDARD_FLAGS} -o ${NAME}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"

clean:
				@echo "$(NAME): $(RED)$(NAME) was removed.$(RESET)"
				@$(REMOVE) $(NAME)

fclean:
				@${REMOVE} ${NAME}
				@echo "${NAME}: ${RED}${NAME} were deleted${RESET}"

re:				fclean all
