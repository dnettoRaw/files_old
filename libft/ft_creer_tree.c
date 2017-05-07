/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creer_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 09:39:50 by dnetto            #+#    #+#             */
/*   Updated: 2017/05/02 14:16:23 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree	*ft_creer_tree(void *nb)
{
	t_tree	*tmp;

	if (!(tmp = (t_tree*)malloc(sizeof(t_tree))))
		return (NULL);
	tmp->value = nb;
	tmp->tgauche = NULL;
	tmp->tdroit = NULL;
	tmp->parent = NULL;
	return (tmp);
}
