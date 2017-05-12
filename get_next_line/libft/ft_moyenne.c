/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moyenne.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 01:24:08 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/28 07:03:40 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_moyenne(int *nb, int len)
{
	int i;
	int *res;

	if (!(res = (int*)malloc(sizeof(int) * 2)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		nb[0] += nb[i];
		i++;
	}
	res[0] = nb[0] / len;
	res[1] = nb[0] % len;
	return (res);
}
