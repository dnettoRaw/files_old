/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_afficher_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 08:24:26 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/29 15:43:51 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_afficher_tree(t_tree *a)
{
	if (a == NULL)
		return ;
	if (a->parent != NULL)
	{
		ft_putchar('(');
		ft_putnbr(a->parent->value);
		ft_putstr(") -> (");
		ft_putnbr(a->value);
		ft_putstr(")\n");
	}
	else
	{
		ft_putchar('(');
		ft_putnbr(a->value);
		ft_putstr(")\n");
	}
	if (a->tgauche != NULL)
		ft_afficher_tree(a->tgauche);
	if (a->tdroit != NULL)
		ft_afficher_tree(a->tdroit);
}
