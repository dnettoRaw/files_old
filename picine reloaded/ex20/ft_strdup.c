/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 08:21:41 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/11 08:30:43 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str, int i)
{
	return ((str[++i]) ? ft_strlen(str, i) : i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*cpy;

	cpy = (char*)malloc(sizeof(*cpy) * (ft_strlen(src, -1) + 1));
	i = -1;
	while (src[++i])
		cpy[i] = src[i];
	cpy[i] = '\0';
	return (cpy);
}
