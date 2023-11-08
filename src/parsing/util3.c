/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:24:03 by ckarl             #+#    #+#             */
/*   Updated: 2023/11/08 09:57:11 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

unsigned int	is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

static void	find_next_token(char *srcString, char *delim)
{
	while (1)
	{
		if (is_delim(*srcString, delim))
		{
			srcString++;
			continue ;
		}
		if (*srcString == '\0')
			return ;
		break ;
	}
}

static void	check_string(char *srcString)
{
	if (!srcString)
		return ;
}

char	*my_strtok(char *srcString, char *delim)
{
	static char	*backup_string;
	char		*ret;

	if (!srcString)
		srcString = backup_string;
	while(*srcString == ' ')
		srcString++;
	check_string(srcString);
	find_next_token(srcString, delim);
	ret = srcString;
	while (1)
	{
		if (*srcString == '\0')
		{
			backup_string = srcString;
			return (ret);
		}
		if (is_delim(*srcString, delim))
		{
			*srcString = '\0';
			backup_string = srcString + 1;
			return (ret);
		}
		srcString++;
	}
}
