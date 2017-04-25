/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 22:57:33 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/24 05:10:22 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>
# define D(y,x) printf("debug ok, %s:%d\n", y, x); 
int	ft_cnt_parts(const char *s, char c)
{
	int		cnt;
	int		in_substring;

	in_substring = 0;
	cnt = 0;
	while (*s != '\0')
	{
		if (in_substring == 1 && *s == c)
			in_substring = 0;
		if (in_substring == 0 && *s != c)
		{
			in_substring = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}
char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		len;
	int 	i;
	int		j;

	i = 0;
	j = 0;
	if(!s)
		return(NULL);
	len = ft_strlen_tool((char*)s, c, 0, 3);
	D("len", len);
	if (!(res = (char**)malloc(sizeof(char*) * len + 1)))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i += ft_strlen_tool(&((char*)s)[i], c, 2, 2);
		if (s[i] != c)
		{
			len = ft_strlen_tool(&((char*)s)[i], c, 1, 2);
			res[j] = ft_strsub(s, i, len);
			D(res[j], j);
			i += len;
			j++;
		}
	}
	res[len + 1][0] = '\0';
	i = 0;
	while (res[i++])
		D(res[i], i); 
	return (res);
}
