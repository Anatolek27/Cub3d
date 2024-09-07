NAME			= Cub3d

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

CC 				= gcc -fsanitize=address

STANDARD_FLAGS 	= -Wall -Werror -Wextra

REMOVE 			= rm -f

SRCS_DIR		= ./sources/

SRCS 			= main.c			\
				parsing/get_file.c	\
				parsing/parsing.c	\
				parsing/get_paths.c	\
				parsing/get_data.c	\
				parsing/rgb.c		\
				parsing/check_paths.c\
				utils/exit.c		\
				utils/utils.c		\
				utils/utils2.c		\
				utils/ft_split.c	\
				gnl/get_next_line.c	\
				gnl/get_next_line_utils.c \

all:			${LIBFT} ${NAME}

${NAME}:
				${CC} ${SRCS} ${LIBFT} ${STANDARD_FLAGS} -o ${NAME}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

clean:
				make clean
				@echo

fclean:
				${REMOVE} ${NAME}
				@echo "${NAME}: ${RED}${NAME} were deleted${RESET}"
				@echo

re:				fclean all

.PHONY:			all clean fclean re rebonus valgrind run run_bon