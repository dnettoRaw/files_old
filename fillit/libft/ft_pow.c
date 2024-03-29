/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:31:02 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/05/04 19:27:09 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_pow(int nb, unsigned int pow)
{
	long	res;

	if (pow == 0)
		return (1);
	res = 1;
	while (pow-- > 0)
		res *= nb;
	return (res);
}
