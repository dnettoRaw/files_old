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
<<<<<<< HEAD
=======
#include<stdio.h>
# define D(y,x) printf("debug ok, %s:%d\n", y, x); 
int	ft_cnt_parts(const char *s, char c)
{
	int		cnt;
	int		in_substring;
>>>>>>> 6fda534b1cdeeb5568b84c00b77690e5f98aefa5

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
<<<<<<< HEAD
	if (!s)
		return (NULL);
	len = ft_strlen_tool((char*)s, c, 0, 3) + 1;
	if (!(res = (char**)malloc(sizeof(char*) * len)))
=======
	if(!s)
		return(NULL);
	len = ft_strlen_tool((char*)s, c, 0, 3);
	D("len", len);
	if (!(res = (char**)malloc(sizeof(char*) * len + 1)))
>>>>>>> 6fda534b1cdeeb5568b84c00b77690e5f98aefa5
		return (NULL);
	res[len - 1] = NULL;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			len = ft_strlen_tool(&((char*)s)[i], c, 1, 2);
<<<<<<< HEAD
			res[j++] = ft_strsub(s, i, len);
=======
			res[j] = ft_strsub(s, i, len);
			D(res[j], j);
>>>>>>> 6fda534b1cdeeb5568b84c00b77690e5f98aefa5
			i += len;
		}
	}
<<<<<<< HEAD
=======
	res[len + 1][0] = '\0';
	i = 0;
	while (res[i++])
		D(res[i], i); 
>>>>>>> 6fda534b1cdeeb5568b84c00b77690e5f98aefa5
	return (res);
}
