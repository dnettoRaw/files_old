/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 23:34:24 by dnetto            #+#    #+#             */
/*   Updated: 2017/05/02 23:35:50 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_ajuter(t_tree *arbre, char **tab, int *i)
{
	if (arbre != NULL)
	{
		ft_ajuter(arbre->tgauche, tab, &(*i));
		tab[(*i)++] = arbre->value;
		ft_ajuter(arbre->tdroit, tab, &(*i));
		return (tab);
	}
	return (NULL);
}

char			**ft_tree_to_tab(t_tree *arbre)
{
	char	**tab;
	int		len;
	int		i;

	i = 0;
	if (arbre == NULL)
		return (NULL);
	len = ft_contnoeud_tree(arbre);
	if (!(tab = (char**)malloc(sizeof(char*) * len + 1)))
		return (NULL);
	tab[len] = NULL;
	tab = ft_ajuter(arbre, tab, &i);
	return (tab);
}
