/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 23:20:42 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/18 23:26:15 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*tmp;

	len = ft_strlen((char*)s1);
	return (!(tmp = (char *)malloc(sizeof(*tmp) * (len + 1)))) ? (NULL) : \
	(ft_strcpy(tmp, (char *)s1));
}
