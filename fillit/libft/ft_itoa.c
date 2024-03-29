/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 16:20:43 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/04/20 19:48:36 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nbrlen(unsigned int n)
{
	return (n > 0 ? ft_nbrlen(n / 10) + 1 : 0);
}

static void			ft_itostr(char *s, unsigned int i)
{
	if (i >= 10)
		ft_itostr(s + 1, i / 10);
	*s = (i % 10) + '0';
}

char				*ft_itoa(int n)
{
	char			*nbr;
	unsigned int	tmp;
	unsigned int	len;
	t_bool			neg;

	neg = (n < 0 ? TRUE : FALSE);
	tmp = (n < 0 ? -n : n);
	len = (n == 0 ? 1 : ft_nbrlen(tmp) + neg);
	if (!(nbr = ft_strnew(len)))
		return (NULL);
	if (neg)
		*nbr = '-';
	ft_itostr(nbr + neg, tmp);
	ft_revstr(nbr + neg);
	return (nbr);
}
