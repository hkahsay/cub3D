# Color Name
GREEN			=	\033[1;32m
YELLOW			= 	\033[33m
BLUE			=	\033[0;34m
BG_GREEN		=	\033[42m
BG_CYAN			=	\033[46m
ENDCOLOR		=	\033[0m

NAME			:=	cub3d

LIBS			:=	ft mlx
LIBS_TARGET		:=	libs/libft/libft.a libs/miniLibX/libmlx.a

INCS			:=	include \
					libs/libft/gnl/include \
					libs/libft/libft/include \
					libs/libft/printf/include  \

SRC_DIR			:=	src

SRCS			:=	main.c \
					mlx/init_mlx.c \
					mlx/handler.c \
					mlx/draw.c \
					data/init_data.c\
					debug/map.c \
					utils/radians.c \
					utils/tab.c \
					utils/draw_utils.c \
					raycast/ray.c

SRCS			:=	$(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR		:=	.build
OBJS			:=	$(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS			:=	$(OBJS:.o=.d)

CC				:=	gcc
CFLAGS			:=	-Wall -Wextra -Werror
CPPFLAGS		:=	$(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS			:=	$(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS			:=	$(addprefix -l,$(LIBS))

RM				:=	rm -f
DIR_DUP			=	mkdir -p $(@D)

all: $(NAME)
	@echo "$(GREEN)Your cub3d is ready to go !$(ENDCOLOR)"

$(NAME): $(LIBS_TARGET) $(OBJS)
	@tput setaf 2; cat ascii_art/cub3d_ascii; tput setaf 7
	@echo "$(BLUE)Compilation des objets lier a cube3d en cours"
	@$(CC) -Llibs/miniLibX -Llibs/libft -framework OpenGL -framework AppKit $(LDLIBS) $(OBJS) -o $(NAME)

$(LIBS_TARGET):
	@$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

-include $(DEPS)

clean:
	@for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	@$(RM) $(OBJS) $(DEPS)

fclean: clean
	@$(MAKE) -C libs/libft fclean
	@$(RM) $(NAME)
	@$(RM) -rf .build

re:
	@$(MAKE) fclean
	@$(MAKE) all

leaks: all
	leaks --atExit -- ./cub3d

debug: re $(LIBS_TARGET) $(OBJS)
	@tput setaf 2; cat ascii_art/cub3d_ascii; tput setaf 7
	@echo "$(BLUE)Compilation des objets lier a cube3d en cours"
	@$(CC) -Llibs/miniLibX -Llibs/libft -framework OpenGL -framework AppKit $(LDLIBS) $(OBJS) -o $(NAME) -g3 -fsanitize=address

.PHONY: all clean fclean re leaks