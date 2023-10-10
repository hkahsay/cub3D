/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:02:08 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/10 15:51:42 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANT_H
# define CONSTANT_H

# define BUFFER_SIZE	42

# define GREEN	"\033[1m\033[32m"
# define RED	"\033[1m\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define VIOLET	"\033[0;36m"
# define RESET	"\033[0m"

# define KEY_ESC	53
# define KEY_EXIT	17
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_W		13
# define KEY_S		1
# define KEY_D		2
# define KEY_A		0
# define KEY_M		46
# define KEY_H		4

# define MAX_WIDTH	1024
# define MAX_HEIGHT	512
# define FOV_ANGLE	60

# define SCALE_GAME		64
# define SCALE_MINI_MAP	15
# define PI				3.14159265359
# define MAX_TEXTURES	5

# define N 1
# define S 2
# define W 3
# define E 4
# define N_E 5
# define N_W 6
# define S_E 7
# define S_W 8
# define north (M_PI / 2)
# define west (M_PI)
# define south (3 * M_PI / 2)
# define east (2 * M_PI)

#endif