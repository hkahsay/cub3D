/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:02:08 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/25 10:25:37 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANT_H
# define CONSTANT_H

# define BUFFER_SIZE	42

# define GREEN	"\033[1;32m"
# define RED	"\033[1;31m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define VIOLET	"\033[1;35m"
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

# define MAX_WIDTH	800
# define MAX_HEIGHT	512
# define FOV_ANGLE	60

# define SCALE_GAME		64
# define SCALE_MINI_MAP	15
# define PI				3.14159265359
# define MAX_TEXTURES	5

# define N 1
# define E 2
# define S 3
# define W 4
# define N_E 5
# define S_E 6
# define S_W 7
# define N_W 8
# define FORWARD 1
# define BACKWARD -1
# define LEFT 1
# define RIGHT 0

#endif