/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contnoeud_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 08:16:08 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/29 13:55:55 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_contnoeud_tree(t_tree *a)
{
	if (a == NULL)
		return (0);
	return (ft_contnoeud_tree(a->tgauche) + ft_contnoeud_tree(a->tdroit) + 1);
}
