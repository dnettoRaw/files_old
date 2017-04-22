/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 00:17:45 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/22 01:04:55 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_skip(char *str, char skip)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (str[++i])
		if (!(str[i] == skip))
			j++;
	return (j);
}

int	 	ft_strlen_stp(char *str, char stp)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == stp)
			return (i);
	return (str[i + 1] ? i : 0);
}

int		ft_strlen_mots (char *str, char esp)
{
	int i;
	int mots;

	i = 0;
	mots = 0;
	if (esp == 32)
	{
		while (str[i])
		{
			while (ft_isesp(str[i++]));
			mots++;
			while (!(ft_isesp(str[i++])));
		}
	}
	else 
	{
		while (str[i])
		{
			while (str[i++] == esp);
			mots++;
			while (str[i++] != esp);
		}
	}
	return (mots);
}

int		ft_strlen_tool(char *str, char c, int nbr)
{
	if (nbr == 0)
		return (ft_strlen(str));
	else if (nbr == 1)
		return (ft_strlen_skip(str, c));
	else if (nbr == 2)
		return (ft_strlen_stp(str, c));
	else if (nbr == 3)
		return (ft_strlen_mots(str, c));
	return (0);
}

int main(int i, char **arg)
{
	i = -1;
	char **str=ft_strsplit(arg[1], *arg[2]);
	printf ("ma phrase : %s\n", arg[1]);	
	printf ("numero de len : %d\n", ft_strlen(arg[1]));	
	printf ("numero de skip : %d\n", ft_strlen_skip(arg[1], *arg[2]));	
	printf ("numero de stp : %d\n", ft_strlen_stp(arg[1], *arg[2]));	
	printf ("numero de mots : %d\n", ft_strlen_mots(arg[1], *arg[2]));
	while (str[++i] != '\0')
		printf ("split ma phase : %s\n", str[i]);	
	return (0);
}
