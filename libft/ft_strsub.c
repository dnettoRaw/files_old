/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 21:17:15 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/21 22:06:49 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	
	if (s == NULL || !(res = ft_memalloc(len + 1)))
		return (NULL);
	ft_strncat(res, &((char*)s)[start], len);
	return (res);
}
