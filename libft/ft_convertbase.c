/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 02:45:06 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/28 09:05:37 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		check_value(int i)
{
	if (i < 10)
		return (i + 48);
	if (i == 10)
		return ('a');
	if (i == 11)
		return ('b');
	if (i == 12)
		return ('c');
	if (i == 13)
		return ('d');
	if (i == 14)
		return ('e');
	if (i == 15)
		return ('f');
	return (0);
}

long				ft_power(long p, int s)
{
	int len;
	long res;

	res = p;
	if (s == 0)
		return (0);
	len = ft_intlen(p);
	while (len > 0)
	{
		res *= p;
		len--;
	}
	return (res);
}

char			*ft_convertbase(unsigned long i, int base)
{
	int				n;
	int				u;
	unsigned long	y;
	char			*str;

	y = i;
	n = 0;
	u = 0;
	if (!i)
		return (ft_itoa(0));
	while (y >= 1)
	{
		y /= base;
		n++;
	}
	str = (char *)malloc((n + 1) * sizeof(char));
	ft_bzero(str, n + 1);
	while (n--)
	{
		str[u++] = check_value(i / ft_power(base, n));
		i = i % (unsigned long)ft_power(base, n);
	}
	return (str);
}
