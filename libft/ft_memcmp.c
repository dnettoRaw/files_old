/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 16:18:34 by dnetto            #+#    #+#             */
/*   Updated: 2017/05/02 14:14:08 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	while (++i - 1 < n)
		if (((unsigned char*)s1)[i - 1] != ((unsigned char*)s2)[i - 1])
			return (((unsigned char*)s1)[i - 1] - ((unsigned char*)s2)[i - 1]);
	return (0);
}
