# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mac <mac@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 20:19:13 by hkahsay           #+#    #+#              #
#    Updated: 2023/09/19 09:14:15 by mac              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# BLUE		= \033[0;34m
# RED			= \033[0;31m
# GREEN		= \033[0;32m
# YELLOW		= \033[0;33m
VIOLET		= \033[0;36m
RESET		= \033[0m

NAME = cub3D
SRCS = 	main.c \
		src/parsing/get_next_line.c \
		src/parsing/get_next_line_utils.c \
		src/parsing/check_error.c \
		src/parsing/util1.c \
		src/parsing/util3.c \
		src/parsing/util2.c \
		src/parsing/util.c \
		src/parsing/checkMap.c \
		src/parsing/init_scene.c \
		src/parsing/parse_scene.c \
		src/parsing/print.c \
		src/parsing/ft_free.c \
		src/parsing/getMap.c \
		src/parsing/parse_texture.c \
		src/parsing/parse_color.c \
		src/parsing/parse_color_tex.c \
		src/rendering/render.c \
		src/rendering/get_texture_pixel.c \
		src/rendering/hook.c \
		src/rendering/mini_map.c \
		src/rendering/get_player.c \
		src/rendering/render_util.c \
		

		

		

OBJS			= ${SRCS:.c=.o}	

CC				= gcc

RM				= rm -f

LIBFT_DIR		= libft

LIBFT			= /libft/libft.a
CFLAGS 			= -g -Wall -Werror -Wextra #-fsanitize=address


INCLUDE			= -L $(LIBFT_DIR) -lft
M_FRAMEWORK		= -framework OpenGL -framework AppKit

MLXPATH			= ./mlx/


INCLUDEMLX		= -I ${MLXPATH}

LMLX			= -L ${MLXPATH} -lmlx


#Rules

all: 	${NAME}
	@echo "$(VIOLET)cub3d is ready to launch !$(RESET)"


.c.o:
		$(CC) ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			$(MAKE) -C $(LIBFT_DIR)
			$(MAKE) -C ${MLXPATH}
			${CC} ${CFLAGS} ${OBJS} ${M_FRAMEWORK} ${INCLUDEMLX} ${LMLX} ${INCLUDE} -o ${NAME} 
clean:		
			${RM} ${OBJS}
			make clean -C $(LIBFT_DIR)
		
			
fclean:		clean
			${RM} $(NAME)
			make fclean -C $(LIBFT_DIR)
			

			
re:			fclean all
leaks: all
	leaks --atExit -- ./cub3d

.PHONY:		all clean fclean re leaks
			