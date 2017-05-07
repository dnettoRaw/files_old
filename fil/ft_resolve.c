/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 20:47:33 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/05/05 01:22:36 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static t_bool	found_empty_block(t_list *tetrimino, char **map,
		t_map_stats *stats, int pos)
{
	int			line;
	int			col;
	int			*p;
	int			row;

	p = (int *)tetrimino->content;
	row = -1;
	while (++row < CONTENT_SIZE)
	{
		line = pos / stats->size;
		pos += p[row];
		if ((p[row] == 1 && line != pos / stats->size)
			|| (p[row] > 1 && line == pos / stats->size))
			return (FALSE);
		line = pos / stats->size;
		col = pos % stats->size;
		if (map[line][col] != EMPTY)
			return (FALSE);
	}
	return (TRUE);
}

static void	ft_add_tetrimino(t_list *tetrimino, char **map,
		t_map_stats *stats, int mode)
{
	int		line;
	int		col;
	int		*p;
	int		row;

	row = -1;
	line = stats->pos / stats->size;
	col = stats->pos % stats->size;
	map[line][col] = (mode == FILL ? stats->letter : EMPTY);
	p = (int *)tetrimino->content;
	while (++row < CONTENT_SIZE)
	{
		stats->pos += p[row];
		line = stats->pos / stats->size;
		col = stats->pos % stats->size;
		map[line][col] = (mode == FILL ? stats->letter : EMPTY);
	}
}

static int		ft_sum_content(t_list *tetrimino)
{
	int			*p;
	int			row;
	int			res;

	row = -1;
	res = 0;
	p = (int *)tetrimino->content;
	while (++row < CONTENT_SIZE)
		res += p[row];
	return (res);
}

static t_bool	valid_pos(t_list *tetrimino, t_map_stats *stats, int pos)
{
	return (pos <= ft_pow(stats->size, 2) - ft_sum_content(tetrimino) + 1 ?
			TRUE : FALSE);
}

int			ft_resolve(t_list *tetrimino, char **map, t_map_stats *stats,
		int pos)
{
	int		line;
	int		col;

	line = pos / stats->size;
	col = pos % stats->size;
	if (!tetrimino)
		return (SUCCESS);
	if (pos >= 15)
		return (FAILURE);
	printf("pos = %d ;map[line=%d][col=%d]=%c\n",pos,line,col,map[line][col]);
	printf("stats pos %d\n", stats->pos);
	if (map[line][col] != EMPTY
		|| (map[line][col] == EMPTY && valid_pos(tetrimino, stats, pos)
			&& !found_empty_block(tetrimino, map, stats, pos)))
		return (ft_resolve(tetrimino, map, stats, pos + 1));
	if (valid_pos(tetrimino, stats, pos)
			&& found_empty_block(tetrimino, map, stats, pos))
	{
		stats->pos = pos;
		ft_add_tetrimino(tetrimino, map, stats, FILL);
		++stats->letter;
		if (ft_resolve(tetrimino->next, map, stats, pos + 1) == SUCCESS)
			return (SUCCESS);
	}
	if (stats->letter > 'A')
		--stats->letter;
	stats->pos = pos;
	ft_add_tetrimino(tetrimino, map, stats, CLEAR);
	return (FAILURE);
}
