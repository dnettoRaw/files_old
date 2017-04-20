/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:52:59 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/13 00:43:35 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	*tmp1;

	i = 0;
	tmp = (unsigned char *)s1;
	tmp1 = (unsigned char *)s2;
	while ((tmp[i] && tmp1[i] && tmp[i] == tmp1[i]) && (i < n))
		i++;
	if (!(n - i))
		return (tmp[i - 1] - tmp1[i - 1]);
	return (tmp[i] - tmp1[i]);
}
