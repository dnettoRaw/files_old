/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 00:09:46 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/29 15:31:58 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*rtmp;
	int		i;

	i = 0;
	if (f == NULL || s == NULL)
		return (NULL);
	if (!(rtmp = (char*)malloc(sizeof(char) * (ft_strlen((char*)s) + 1))))
		return (NULL);
	while (s[i++])
		rtmp[i - 1] = f(s[i - 1]);
	rtmp[i - 1] = '\0';
	return (rtmp);
}
