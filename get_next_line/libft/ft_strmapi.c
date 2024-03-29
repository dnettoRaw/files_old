/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 00:09:46 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/29 15:44:33 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rtmp;
	int		i;

	i = 0;
	if (f == NULL || s == NULL)
		return (NULL);
	if (!(rtmp = (char*)malloc(sizeof(char) * (ft_strlen((char*)s) + 1))))
		return (NULL);
	while (s[i++])
		rtmp[i - 1] = f(i - 1, s[i - 1]);
	rtmp[i - 1] = '\0';
	return (rtmp);
}
