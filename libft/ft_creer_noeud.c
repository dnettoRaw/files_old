/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creer_noeud.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 06:53:08 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/29 15:46:50 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_creer_noeud(t_tree **arbre, t_tree **parent, void *value)
{
	t_tree	*noeud;

	if (!(noeud = (t_tree*)malloc(sizeof(t_tree))))
		return ;
	noeud->value = value;
	noeud->tgauche = NULL;
	noeud->tdroit = NULL;
	noeud->parent = *parent;
	*arbre = noeud;
}
