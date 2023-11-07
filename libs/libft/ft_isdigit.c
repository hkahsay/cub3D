/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:39:43 by hkahsay           #+#    #+#             */
/*   Updated: 2023/10/27 14:48:11 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <unistd.h>
#include <stdio.h>*/

int	ft_isdigit(int x)
{
	if ((x >= '0') && (x <= '9'))
		return (1);
	else
		return (0);
}

int	ft_isdijit_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*int	main()
{
	int x;

	x = 6;
	printf ("%d", ft_isdigit(x));
}*/