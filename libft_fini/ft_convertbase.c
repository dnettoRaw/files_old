/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:47:31 by dnetto            #+#    #+#             */
/*   Updated: 2017/05/02 18:51:38 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define HEX(x) "0123456789abcdef"[x]

char	*ft_convertbase(unsigned int nb, int base)
{
	char	*res;
	int		len;
	int		i;

	i = nb;
	len = 1;
	while ((i /= base))
		len++;
	res = (char*)malloc(sizeof(char) * (len + 1));
	res[len] = '\0';
	while (len)
	{
		res[--len] = HEX(nb % base);
		nb /= base;
	}
	return (res);
}
