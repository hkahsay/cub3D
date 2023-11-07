# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 20:19:13 by hkahsay           #+#    #+#              #
#    Updated: 2023/11/03 16:58:59 by ckarl            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	### COMPILATION ###
CC			:=	gcc
CFLAGS		:=	-g -Wall -Wextra -Werror #-fsanitize=address

	### EXECUTABLE ###
NAME		:=	cub3D

	### LIBS ###
LIBFT_PATH	:= ./libs/libft/
LIBFT		:= ${LIBFT_PATH}libft.a
MLXPATH		:= ./libs/mlx/
MLX			:= ${MLXPATH}libmlx.a
INCLUDE		:= -I${MLXPATH} -I${LIBFT_PATH}
LIBS		:= -L${MLXPATH} -lmlx -L${LIBFT_PATH} -lft
M_FRAMEWORK	:= -framework OpenGL -framework AppKit

	### PATH ###
SRCS_PATH	:= src
OBJS_PATH	:= obj
INCS_PATH	:= -Iincludes

	### COLORS ###
BLUE		:=	\033[0;34m
RED			:=	\033[0;31m
GREEN		:=	\033[0;32m
YELLOW		:=	\033[0;33m
VIOLET		:=	\033[0;36m
RESET		:=	\033[0m

	### SOURCE FILES ###
MAIN_FILE	:=	main.c \

PARSE_FILES	:=	get_next_line.c			\
				get_next_line_utils.c	\
				check_error.c			\
				util1.c					\
				util3.c					\
				util2.c					\
				util4.c					\
				checkMap.c				\
				init_scene1.c			\
				init_scene2.c			\
				parse_scene.c			\
				ft_split_ck.c			\
				print.c					\
				ft_free.c				\
				read_scene.c			\
				getMap.c				\
				parse_texture.c			\
				parse_color.c			\
				parse_color_tex.c		\

REND_FILES	:=	render_game.c			\
				get_texture_pixel.c		\
				hook.c					\
				render_minimap.c		\
				get_player.c			\
				ray_init.c				\
				ray_horizontal.c		\
				ray_vertical.c			\
				ray_utils1.c			\
				ray_utils2.c			\
				draw_C_F.c				\
				movement.c				\
				movement_utils1.c		\
				movement_utils2.c		\
				exit.c					\
				init_mlx.c				\

	### OBJECTS ###
MAIN_FILE	:= $(addprefix $(OBJS_PATH)/, $(MAIN_FILE:.c=.o))
PARSE_FILES	:= $(addprefix $(OBJS_PATH)/parsing/, $(PARSE_FILES:.c=.o))
REND_FILES	:= $(addprefix $(OBJS_PATH)/rendering/, $(REND_FILES:.c=.o))

OBJS		:=	${MAIN_FILE}	\
				${PARSE_FILES}	\
				${REND_FILES}	\

	### RULES ###

all:	${NAME}
	@echo "$(VIOLET)cub3d is ready to launch !$(RESET)"

${LIBFT}:
	@echo "$(GREEN)Compilating Libft$(RESET)"
	@$(MAKE) -sC $(LIBFT_PATH)
	@echo "$(CYAN)✔️  Compilation Done$(RESET)"
	@cp ${LIBFT_PATH}libft.a .

${MLX}:
	@echo "$(GREEN)Compilating Minilibx$(RESET)"
	@$(MAKE) -sC $(MLXPATH)
	@echo "$(CYAN)✔️  Compilation Done$(RESET)"
	@cp ${MLXPATH}libmlx.a .

.c.o:
		$(CC) ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${MLX} ${LIBFT} ${OBJS}
			@echo "$(GREEN)Compilating cub3D$(RESET)"
			@${CC} ${CFLAGS} ${M_FRAMEWORK} ${LIBS} -o $@ ${OBJS}
			@echo "$(CYAN)✔️  Compilation Done$(RESET)"

tmp:d
			@mkdir -p objs

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INCS_PATH) -c $< -o $@

clean:
			@echo "$(RED) Cleaning Directory /includes/libft$(RESET)"
			@$(MAKE) -sC $(LIBFT_PATH) clean

			@echo "$(RED) Cleaning Directory /objs$(RESET)"
			@rm -rf $(OBJS_PATH)
			@echo "$(RED) Cleaning Directory /includes/mlx$(RESET)"
			@$(MAKE) -sC $(MLXPATH) clean

fclean:		clean
			@$(MAKE) -sC $(LIBFT_PATH) fclean
			@echo "$(RED) rm libft.a libmlx.a cub3D$(RESET)"
			@rm -f libft.a
			@rm -f libmlx.a
			@rm -rf $(NAME)

re:			fclean all

leaks:		all
	leaks --atExit -- ./cub3d

.PHONY:		all clean fclean re leaks

###need to add this to clean in the end###
#@echo "$(RED) Cleaning Directory /includes/mlx$(RESET)"
#@$(MAKE) -sC $(MLXPATH) clean

###need to add this to fclean in the end###
#@rm -f libmlx.a