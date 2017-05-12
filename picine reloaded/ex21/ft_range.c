/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 08:33:42 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/11 08:36:27 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*res;
	int	i;

	if (min >= max)
		return (0);
	res = (int *)malloc(sizeof(int) * (max - min));
	if (res)
	{
		i = min;
		while (i < max)
		{
			res[i - min] = i;
			i++;
		}
	}
	return (res);
}
