/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 22:57:33 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/26 01:18:37 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = ft_strlen_tool((char*)s, c, 0, 3) + 1;
	if (!(res = (char**)malloc(sizeof(char*) * len)))
		return (NULL);
	res[len - 1] = NULL;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			len = ft_strlen_tool(&((char*)s)[i], c, 1, 2);
			res[j++] = ft_strsub(s, i, len);
			i += len;
		}
	}
	return (res);
}
