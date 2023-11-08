/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:35:24 by ckarl             #+#    #+#             */
/*   Updated: 2023/11/08 09:57:16 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_strlen_trim(char *str, char c)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

int	tab_size(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

char	**trimmed_colors(char **tab, char c)
{
	char	**trimmed;
	int		i;

	trimmed = malloc(sizeof(char *) * (tab_size(tab) + 1));
	if (!trimmed)
		return (NULL);
	i = -1;
	while (tab[++i])
	{
		trimmed[i] = ft_strtrim(tab[i], &c);
		if (!ft_strcmp(trimmed[i], ""))
		{
			ft_error_msg(RED"Error\nCould not split color components."RESET);
			return (NULL);
		}
	}
	trimmed[i] = 0;
	return (trimmed);
}
