/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_buf_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:28:58 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/04/27 21:56:24 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	count_newlines(char c, int *stats, t_bool first_read)
{
	if ((first_read && c == '\n' && (stats[INDEX] + 1) % 5 == 0)
			|| (!first_read && c == '\n' &&
			((stats[INDEX] == 0) || stats[INDEX] % 5 == 0)))
		++stats[NL];
}

void	count_hashmarks(char c, int *stats)
{
	if (c == '#')
	{
		if (stats[HASHT] == 0)
			stats[FIRST_HASHT_L] = stats[NL];
		++stats[HASHT];
	}
}

void	count_dots(char c, int *stats)
{
	if (c == '.')
		++stats[DOTS];
}

void	count_step(char c, int *stats)
{
	if (stats[HASHT] > 0 && c != '\n')
		++stats[STEP];
}
