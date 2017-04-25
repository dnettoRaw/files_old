/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 00:17:45 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/24 05:10:28 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
int		ft_strlen_letres(char *str, char skip)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[++i])
		if (!(str[i] == skip))
			j++;
	return (j);
}

int	 	ft_strlen_c(char *str, char stp, int dif)
{
	int i;
	int k;

	i = 0;
	if (dif >= 3 && dif <= 4)
		k = ft_strlen(str);
	if (dif == 1)
		while (str[i] && str[i] != stp)
			i++;
	else if (dif == 2)
		while ((str[i]) && (str[i] == stp))
			i++;
	else if (dif == 3)
		while (--k >= 0 && str[k] != stp)
			i++;
	else if (dif == 4)
		while (--k >= 0 && str[k] == stp)
			i++;
	return (i);
}

int		ft_strlen_mots(char *str, char esp, int k)
{
	int i;
	int mots;

	i = 0;
	mots = 0;
	if (k == 1)
		while (str[++i])
		{
			k = 0;
			while (!(ft_isesp(str[i])) && str[i])
				if (k == 0)
					mots += (i++ >= 0) ? ++k : ++k;
				else
					i++;
		}
	else 
		while (str[++i])
		{
			k = 0;
			while (str[i] != esp && str[i])
				if (k == 0)
					mots += (i++ >= 0) ? ++k : ++k;
				else
					i++;
		}
	return (mots);
}

int		ft_strlen_tool(char *str, char c, int nb, int nbr)
{	
	if (nbr == 0)
		return (ft_strlen(str));
	else if (nbr == 1)
		return (ft_strlen_letres(str, c));
	else if (nbr == 2)
		return (ft_strlen_c(str, c, nb));
	else if (nbr == 3)
		return (ft_strlen_mots(str, c, nb));
	return (0);
}

#include<stdio.h>
int main(int i, char **arg)
{
		i = 0;
		char **str=ft_strsplit(arg[1], *arg[2]);
	printf ("ma phrase : \"%s\"\t\t c = \"%c\"\n", arg[1], *arg[2]);	
	printf ("\nnumero de letres : %d\n", ft_strlen_letres(arg[1], *arg[2]));
	printf ("numero de mots : %d\n", ft_strlen_mots(arg[1], *arg[2], 0));
	printf ("numero de len : %d\n\n", ft_strlen(arg[1]));	
	printf ("numero de str++ != c : %d\n", ft_strlen_c(arg[1], *arg[2], 1));	
	printf ("numero de str++ == c : %d\n", ft_strlen_c(arg[1], *arg[2], 2));	
	printf ("numero de str-- != c : %d\n", ft_strlen_c(arg[1], *arg[2], 3));	
	printf ("numero de str-- == c : %d\n\n", ft_strlen_c(arg[1], *arg[2], 4));	
	while (str[i] != 0)
		{
			printf ("split ma phase : |%s|\n", str[i++]);	
		}
	return (0);
}
