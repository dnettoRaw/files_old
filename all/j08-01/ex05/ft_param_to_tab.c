/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:40:31 by dnetto            #+#    #+#             */
/*   Updated: 2017/03/30 14:34:02 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"
#include <stdlib.h>

int						ft_len(char *str, int i)
{
	return ((str[++i]) ? ft_len(str, i) : i);
}

char					*ft_strdup(char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i])
		i++;
	res = (char*)malloc(sizeof(char) * i);
	i = -1;
	while (str[++i])
		res[i] = str[i];
	res[i] = '\0';
	return (res);
}

struct	s_stock_par		*ft_param_to_tab(int ac, char **av)
{
	t_stock_par	*tab;
	int			i;


	tab = (t_stock_par *)malloc(sizeof(t_stock_par) * (ac + 1));
	i = -1;
	if (!tab)
		return ((t_stock_par *)0);
	while (++i < ac)
	{
		tab->size_param = ft_len(av[i], -1);
		tab->str = av[i];
		tab->copy = ft_strdup(av[i]);
		tab->tab = ft_split_whitespaces(av[i]);
	}
	tab[i].str = 0;
	return (tab);
}
