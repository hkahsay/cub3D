/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:19:35 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/27 17:31:57 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_isdigit_strict(const char *str)
{
	if (*str == '-' || *str == '+' || *str == ' ')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	empty_color(char *str)
{
	if (!str)
	{
		ft_error_msg(RED"Error\nColor is not set."RESET);
	}
}

void	empty_reso(char *str)
{
	if (!str)
	{
		ft_error_msg(RED"Error\nResolution is not set."RESET);
	}
}
