/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 01:28:22 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/29 14:45:14 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char **ft_tree_to_tab(t_tree *arbre);
int main(int i,char **argv)
{
	if (i < 2)
		return (0);
	i = 1;
	t_tree *arbre;
	 arbre = ft_creer_tree(argv[i]);
	while (argv[++i])
	 ft_ajouterdata_tree(&arbre, argv[i]);
	printf("nombre de noeud = %d\n",ft_contnoeud_tree(arbre));
	ft_afficher_tree(arbre->tgauche);

/*
	ft_putstr("\nvaleur de mon abre\n");
	ft_putstr(arbre->value);
	ft_putstr("\nvaleur de mon abre->gauche\n");
	ft_putstr(arbre->tgauche->value);
	ft_putstr("\nvaleur de mon abre->droit\n");
	ft_putstr(arbre->tdroit->value);
*/
	char **tab;
	i = -1;
	tab = ft_tree_to_tab(arbre);
	while (tab[++i])
		ft_putstr(tab[i]);
	ft_effacer_tree(arbre);
	return(0);
}
