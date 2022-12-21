# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRCS    = 	cub3d.c\
			cub3d_utils.c\
			cub3d_utils_2.c\
			cub3d_check_errors.c\
			cub3d_check_errors_2.c\
			cub3d_make_tab.c\
			cub3d_make_colors.c\
			cub3d_init.c\
			cub3d_destroy.c\
			cub3d_make_path.c

DIR_SRC_CUB3D = ./sources/srcs_cub3d/

OBJ	= ${SRCS:.c=.o}
DIR_OBJ = sources/objs/
OBJS = $(addprefix $(DIR_OBJ), $(OBJ))

DEP = ${SRCS:.c=.d}
DEPS = $(addprefix $(DIR_OBJ), $(DEP))

LMLX	= -L minilibx-linux -lmlx -lXext -lX11 -lm
NAME = cub3d

HEADERS	= -I includes minilibx-linux
CC		= gcc
CFLAGS	= -MMD -Wall -Wextra -Werror

${NAME} :	${OBJS}
			@make -C ./sources/libft
			@make -C minilibx-linux
			@echo "$(CYAN)cub3d compiled!$(DEF_COLOR)"
			@${CC} ${CFLAGS} ${OBJS} ./sources/libft/libft.a -o ${NAME} ${LMLX}

all :		cub3d

clean:
			@rm -f ${OBJS} ${DEPS}
			@echo "$(BLUE)cub3d cleaned$(DEF_COLOR)"

fclean:		clean
			@make -C ./sources/libft fclean
			@make -C minilibx-linux clean
			@rm -f cub3d

re:			fclean all

$(DIR_OBJ)%.o: $(DIR_SRC_CUB3D)%.c
	@echo "$(BLUE)Compiling: $< $(DEF_COLOR)"
	@${CC} ${CFLAGS} -c $< ${HEADERS} -o $@

-include ${DEPS}

.PHONY: all clean fclean re