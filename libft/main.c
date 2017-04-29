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

int main(int i,char **argv)
{
	if (i < 2)
		return (0);
	i = 1;
	t_tree *arbre;
	 arbre = ft_creer_tree(ft_atoi(argv[i]));
	while (argv[++i])
	 ft_ajouterdata_tree(&arbre, ft_atoi(argv[i]));
	printf("nombre de noeud = %d\n",ft_contnoeud_tree(arbre));
	ft_afficher_tree(arbre);
	if (arbre == NULL)
		return (0);
	ft_effacer_tree(arbre);
	return(0);
}
