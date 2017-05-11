/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:35:26 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/05/10 00:07:29 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lstincrement(t_list *list, int value)
{
	int	*p;
	int	i;

	if (list)
		while (list)
		{
			i = -1;
			p = (int *)list->content;
			while (++i < CONTENT_SIZE)
			{
				if (value == -1 && p[i] == 2)
					p[i] = -2;
				if (p[i] > 1)
					p[i] += value;
				if (value > 0 && p[i] == -2)
					p[i] = 2;
			}
			list = list->next;
		}
}
