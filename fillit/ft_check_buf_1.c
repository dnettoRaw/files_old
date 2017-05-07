/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_buf_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 15:23:04 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/05/01 15:27:00 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static int		g_comb[COMBINATIONS][CONTENT_SIZE] = {{1, 1, 1}, {1, 1, 2},
	{1, 1, 3}, {1, 1, 4}, {1, 2, 1}, {1, 3, 1}, {1, 4, 1}, {1, 3, 4}, {1, 4, 4},
	{2, 1, 1}, {3, 1, 1}, {3, 1, 3}, {3, 1, 4}, {4, 1, 1}, {4, 1, 3}, {4, 1, 4},
	{4, 3, 1}, {4, 4, 1}, {4, 4, 4}};

static t_bool	invalid_c(char c)
{
	return (c != '.' && c != '#' && c != '\n' ? TRUE : FALSE);
}

static t_bool	valid_stats(int *stats, int *comb, t_bool first_read)
{
	int			i;
	int			max_nl;

	max_nl = (first_read ? MAX_NL - 1 : MAX_NL);
	i = 0;
	while (i < COMBINATIONS && ft_int_tab_cmp(comb, g_comb[i]) != SUCCESS)
		++i;
	return (i == COMBINATIONS
			|| stats[HASHT] != MAX_HASHT
			|| stats[NL] != max_nl
			|| stats[DOTS] != MAX_DOTS ? FALSE : TRUE);
}

static void		fill_comb(char c, int *comb, int *stats)
{
	if (c == '#' && stats[HASHT] > 1 && stats[ROW] < CONTENT_SIZE)
	{
		if (stats[HASHT] == 2
				&& ((stats[STEP] > 1 && stats[FIRST_HASHT_L] == stats[NL])
					|| (stats[STEP] == 1 && stats[FIRST_HASHT_L] != stats[NL])))
			stats[STEP] = STEP_ERR;
		comb[stats[ROW]] = stats[STEP];
		stats[STEP] = 0;
		++stats[ROW];
	}
}

static void		*free_and_quit(int *comb)
{
	free(comb);
	return (NULL);
}

int				*ft_check_buf(char *buf, t_bool first_read)
{
	int			stats[STATS_SIZE];
	int			*comb;

	stats[INDEX] = -1;
	stats[ROW] = 0;
	stats[STEP] = 0;
	stats[HASHT] = 0;
	stats[NL] = 0;
	stats[DOTS] = 0;
	if (!(comb = (int *)malloc(sizeof(*comb) * CONTENT_SIZE)))
		return (NULL);
	ft_bzero(comb, CONTENT_SIZE * sizeof(int));
	while (buf[++stats[INDEX]])
	{
		count_newlines(buf[stats[INDEX]], stats, first_read);
		count_dots(buf[stats[INDEX]], stats);
		count_step(buf[stats[INDEX]], stats);
		count_hashmarks(buf[stats[INDEX]], stats);
		fill_comb(buf[stats[INDEX]], comb, stats);
		if (invalid_c(buf[stats[INDEX]]))
			return (NULL);
	}
	return (valid_stats(stats, comb, first_read) ? comb : free_and_quit(comb));
}
