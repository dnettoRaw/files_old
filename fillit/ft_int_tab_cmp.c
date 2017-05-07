/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_tab_cmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 20:25:34 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/04/26 12:34:24 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_int_tab_cmp(int *a, int *b)
{
	int	i;

	i = 0;
	while (i < CONTENT_SIZE)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		++i;
	}
	return (SUCCESS);
}
