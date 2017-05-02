/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ajouterdata_tree.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 06:44:14 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/29 16:26:20 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_ajouterdata_tree(t_tree **arbre, void *nb)
{
	if (*arbre == NULL)
		ft_creer_noeud(arbre, NULL, nb);
	else
	{
		if (ft_memcmp((*arbre)->value, nb, ft_strlen((char*)nb)) > 0)
		{
			if ((*arbre)->tgauche == NULL)
				ft_creer_noeud(&(*arbre)->tgauche, &(*arbre), nb);
			else
				ft_ajouterdata_tree(&(*arbre)->tgauche, nb);
		}
		if (ft_memcmp((*arbre)->value, nb, ft_strlen((char*)nb)) < 0)
		{
			if ((*arbre)->tdroit == NULL)
				ft_creer_noeud(&(*arbre)->tdroit, &(*arbre), nb);
			else
				ft_ajouterdata_tree(&(*arbre)->tdroit, nb);
		}
	}
}
