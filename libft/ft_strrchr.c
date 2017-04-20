/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 22:26:58 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/18 23:18:49 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen((char*)s) + 1;
	while (--i > 0)
		if (((char*)s)[i] == c)
			return (&((char*)s)[i]);
	return ((((char*)s)[i] == c) ? &((char*)s)[i] : 0);
}
