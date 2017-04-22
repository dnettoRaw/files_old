/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 22:57:33 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/22 01:04:09 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i1;
	int		i2;
	int		len;

	i1 = 0;
	i2 = 0;
	res = (char**)malloc(sizeof(char*) * ft_strlen_tool((char*)s, c, 3));
	if (s == NULL || c == 0)
		return (NULL);
	while (s[i1])
	{
		while (s[i1] == c)
			i1++;
		len = ft_strlen_tool(&((char*)s)[i1], c, 2);
		res[i2] = ft_strsub(s, i1, len);	
		i2++;
		while (s[i1] != c && s[i1])
			i1++;
	}
	res[i2][0] = '\0';
	return (res);
}
