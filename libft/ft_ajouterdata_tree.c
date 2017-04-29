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

void		ft_ajouterdata_tree(t_tree **arbre, int nb)
{
	if (*arbre == NULL)
		ft_creer_noeud(arbre, 0, nb);
	else
	{
		if ((*arbre)->value > nb)
		{
			if ((*arbre)->tgauche == NULL)
				ft_creer_noeud(&(*arbre)->tgauche, &(*arbre), nb);
			else
				ft_ajouterdata_tree(&(*arbre)->tgauche, nb);
		}
		if ((*arbre)->value < nb)
		{
			if ((*arbre)->tdroit == NULL)
				ft_creer_noeud(&(*arbre)->tdroit, &(*arbre), nb);
			else
				ft_ajouterdata_tree(&(*arbre)->tdroit, nb);
		}
	}
}
