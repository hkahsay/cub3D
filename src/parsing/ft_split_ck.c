/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:19:20 by ckarl             #+#    #+#             */
/*   Updated: 2023/10/27 15:11:45 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_words(char const *s, char c)
{
	int	i;
	int	count;
	int	point;

	point = 1;
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && point == 1)
		{
			count += 1;
			point = 0;
		}
		else if (s[i] == c)
			point = 1;
		i++;
	}
	return (count);
}

char	*ft_dup(char const *str, int start, int end)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(sizeof(*copy) * (end - start + 1));
	if (!copy)
		return (NULL);
	while (start < end)
		copy[i++] = str[start++];
	copy[i] = '\0';
	return (copy);
}

char	**ft_split_ck(char const *s, char c)
{
	char	**tab;
	int		i;
	int		a;
	int		start;

	i = 0;
	a = 0;
	start = -1;
	tab = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1));
	if (!tab || !s)
		return (NULL);
	while (i <= ft_len(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_len(s)) && start >= 0)
		{
			tab[a++] = ft_dup(s, start, i);
			start = -1;
		}
		i++;
	}
	tab[a] = 0;
	return (tab);
}
