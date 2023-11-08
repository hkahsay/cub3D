/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:10:08 by ckarl             #+#    #+#             */
/*   Updated: 2023/11/08 09:56:56 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_check_char(char *str, char c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13) || c == '\0')
		return (1);
	return (0);
}

void	skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (is_space((str[i])))
		i++;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}
