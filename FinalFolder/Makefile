NAME			= Cub3d

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

CC 				= cc

STANDARD_FLAGS 	= -Wall -Wextra -Werror

REMOVE 			= rm -f

SRCS 			= main.c				\
					srcs/utils/ft_exit.c\
					srcs/utils/utils.c

all:			${NAME}

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