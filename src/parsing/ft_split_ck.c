/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:19:20 by ckarl             #+#    #+#             */
/*   Updated: 2023/11/01 15:20:34 by ckarl            ###   ########.fr       */
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
	{
		printf("in dup return\n");
		return (NULL);
	}
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
	// printf("ft_words: %d\n", ft_words(s, c));
	tab = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1));
	if (!tab || !s)
		return (NULL);
	// printf("ft len: %d and split char '%c'\n", ft_len(s), c);
	while (i <= ft_len(s))
	{
		if (s[i] != c && start < 0)
		{
			// printf("printf start '%c'\n", s[i]);
			start = i;
		}
		else if ((s[i] == c || i == ft_len(s)) && start >= 0)
		{
			// if (s[i] == '\0')
			// 	printf("it's 0\n");
			// printf("in tab[a++]and char i -%c- hello\n", i);
			tab[a++] = ft_dup(s, start, i);
			start = -1;
		}
		i++;
	}
	// if (start >= 0)
	// {
	// 	printf("in if outside of while start %d and i %d\n", start, i);
	// 	tab[a++] = ft_dup(s, start, i);
	// }
	// printf("value of i %d\n", i);
	tab[a] = 0;
	return (tab);
}
