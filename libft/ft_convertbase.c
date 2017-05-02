/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 02:45:06 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/29 16:26:09 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

static char		ft_check(int i)
{
	if (i < 10)
		return (i + 48);
	else if (i == 10)
		return ('a');
	else if (i == 11)
		return ('b');
	else if (i == 12)
		return ('c');
	else if (i == 13)
		return ('d');
	else if (i == 14)
		return ('e');
	else if (i == 15)
		return ('f');
	return (0);
}

char			*ft_convertbase(unsigned int nb, int base)
{
	char	*res;
	char	*c;
	int	len;
	int	i;

	i = 0;
	len = ft_intlen(nb);
	c = (char*)malloc(sizeof(char) * 2);
	c[1] = '\0';
	printf("nb = %d\tbase =%d\tlen =%d\n",nb, base, len);
	while (nb > 0)
	{
		c[0] = ft_check(nb % base);
		res = ft_strjoin((char const*)res, (char const*)c);
		nb /= base;
		i++;
	}
	free(c);
	return (ft_strrev(&res[ft_strlen(res) - i]));
}
