/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 01:56:27 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/19 02:06:28 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rest;
	int		l;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l = ft_strlen((char*)s2);
	if (!(rest = (char*)malloc(sizeof(char) * (ft_strlen((char*)s1) + l + 1))))
		return (NULL);
	ft_strcpy(rest, (char*)s1);
	ft_strcat(rest, (char*)s2);
	return (rest);
}
