/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_to_tab.c	                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 06:44:14 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/29 16:26:20 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void		ft_ajuter(t_tree *arbre, char ***tab, int i, int len)
{
	if (arbre != NULL)	
	{
		ft_ajuter(arbre->tgauche, &(*tab), i, --len);
		printf("arbre value = %s\ti=%d\tlen=%d\n", arbre->value,++i,len);
		ft_ajuter(arbre->tdroit, &(*tab), i, --len);
	}
}

char		**ft_tree_to_tab(t_tree *arbre)
{
	char	**tab;
	int	len;

	if (arbre == NULL)
		return (NULL);
	len = ft_contnoeud_tree(arbre);
	if (!(tab = (char**)malloc(sizeof(char*) * len + 1)))
		return (NULL);
	tab[len] = NULL;
	ft_ajuter(arbre, &tab, 0, len);
//printf("len de ma tab : %d\tarbre:%d\nstr=%s\n", ft_strlen(*tab), ft_contnoeud_tree(arbre), tab[0]);
	int i = 0;

	while (i++ < 3)
		printf("abre[i]=%s\n", arbre[i].value);
	return (tab);
}
