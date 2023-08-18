# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 20:19:13 by hkahsay           #+#    #+#              #
#    Updated: 2023/08/18 17:14:18 by hkahsay          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# BLUE		= \033[0;34m
# RED			= \033[0;31m
# GREEN		= \033[0;32m
# YELLOW		= \033[0;33m
VIOLET		= \033[0;36m
RESET		= \033[0m

NAME = cub3D
SRCS = 	src/ray.c \
		src/check_error.c \
		main.c \
		src/get_next_line.c \
		src/get_next_line_utils.c \

OBJS			= ${SRCS:.c=.o}	

CC				= gcc

RM				= rm -f

LIBFT_DIR		= libft

LIBFT			= /libft/libft.a
CFLAGS 			= -g -Wall -Werror -Wextra


INCLUDE			= -L $(LIBFT_DIR) -lft
M_FRAMEWORK		= -framework OpenGL -framework AppKit

MLXPATH			= ./mlx/


INCLUDEMLX		= -I ${MLXPATH}

LMLX			= -L ${MLXPATH} -lmlx


#Rules

all: 	${NAME}
	@echo "$(VIOLET)cub3d is ready to launch !$(ENDCOLOR)"


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
			