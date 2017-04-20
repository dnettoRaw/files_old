/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 23:18:57 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/19 22:11:18 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nb)
{
	int		i;
	long	t;
	char	*res;

	i = 1;
	t = nb;
	if (nb == -2147483648 || nb == 0)
		return (nb == 0 ? ft_strdup("0") : ft_strdup("-2147483648"));
	while (t /= 10)
		i++;
	if (!(res = (char *)malloc(sizeof(char) * ((nb < 0 ? ++i : i) + 1))))
		return (NULL);
	res[i--] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	while (nb)
	{
		res[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	return (res);
}
