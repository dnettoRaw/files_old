/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 00:09:46 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/19 00:56:12 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*rtmp;
	int		i;

	i = -1;
	if (f == NULL || s == NULL)
		return (NULL);
	if (!(rtmp = (char*)malloc(sizeof(char) * (ft_strlen((char*)s) + 1))))
		return (NULL);
	while (s[++i])
		rtmp[i] = f(s[i]);
	rtmp[i] = '\0';
	return (rtmp);
}
