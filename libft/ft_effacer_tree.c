/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_effacer_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 06:49:55 by dnetto            #+#    #+#             */
/*   Updated: 2017/05/02 14:14:29 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_effacer_tree(t_tree *arbre)
{
	if (arbre == NULL)
		return ;
	ft_effacer_tree(arbre->tgauche);
	ft_effacer_tree(arbre->tdroit);
	free(arbre);
}
