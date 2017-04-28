/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 00:28:11 by dnetto            #+#    #+#             */
/*   Updated: 2017/03/30 08:48:00 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		esp(char str)
{
	if (str == ' ' || str == '\t' || str == '\n')
		return (1);
	return (0);
}

int		ft_mots(char *str)
{
	int i;
	int j;
	int	res;

	i = -1;
	res = 0;
	while (str[++i])
	{
		j = 0;
		while ((!esp(str[i])) && str[i])
		{
			if (j == 0)
			{
				j = 1;
				i++;
				res++;
			}
			else
				i++;
		}
	}
	return (res);
}

int		ft_strlen(char *str, int j)
{
	int i;

	i = 0;
	while (str[j] && !esp(str[j]))
	{
		i++;
		j++;
	}
	return (i);
}

char	*ft_ecrir(char *dest, char *str, int j)
{
	int i;
	int size;

	i = 0;
	size = ft_strlen(str, j);
	while (i < size)
	{
		dest[i] = str[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split_whitespaces(char *str)
{
	int		j;
	int		mots;
	int		i;
	char	**tab;

	j = 0;
	mots = ft_mots(str);
	i = 0;
	if (!(tab = (char**)malloc(sizeof(char *) * (mots + 1))))
		return (NULL);
	while (str[j] && i < mots)
	{
		while (esp(str[j]) == 1)
			j++;
		if (!(tab[i] = (char*)malloc(sizeof(char) * (ft_strlen(str, j) + 1))))
			return (NULL);
		ft_ecrir(tab[i], str, j);
		j = j + ft_strlen(str, j);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
