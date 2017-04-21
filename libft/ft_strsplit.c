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
	
	i1 = -1;
	i2 = 0;
	res = ;
	if (s == NULL || c == 0)
		return (NULL);
	while (s[++i1])
	{
		if (s[i1] != c)
		{
			len = ft_strlen_itstp(&((char*)s)[i1], c);
			res[i2] = ft_strsub(s, i1, len);
			i2++;
			i1 = len - 1;
		}
		while (s[i1] == c);
	}
	return (res);
}

int main()
{
	char *s="zxcvbnm***abc**cd**";
	char **tab=ft_strsplit(s, '*');
	int i = -1;
	
	while (tab[++i])
		printf ("n*%d : %s\n", i, tab[i]);
}
