/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 20:47:33 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/05/07 21:12:20 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

static void		ft_add_tetrimino(t_list *tetrimino, char **map,
		t_map_stats *stats, int mode)
{
	int			line;
	int			col;
	int			*p;
	int			row;

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

static t_bool	valid_pos(t_list *tetrimino, char **map,
		t_map_stats *stats, int pos)
{
	int			line;
	int			col;

	line = pos / stats->size;
	col = pos % stats->size;
	return ((pos <= ft_pow(stats->size, 2) - ft_sum_content(tetrimino) - 1)
			&& map[line][col] == EMPTY ?
			TRUE : FALSE);
}

int				ft_resolve(t_list *tetrimino, char **map, t_map_stats *stats,
		int pos)
{
	if (!tetrimino)
		return (SUCCESS);
	if (found_empty_block(tetrimino->next, map, stats, pos))
		return (ft_resolve(tetrimino->next, map, stats, pos));
	else if (valid_pos(tetrimino, map, stats, pos) &&
			found_empty_block(tetrimino, map, stats, pos))
	{
		stats->pos = pos;
		ft_add_tetrimino(tetrimino, map, stats, FILL);
		++stats->letter;
		if (ft_resolve(tetrimino->next, map, stats, 0) == SUCCESS)
			return (SUCCESS);
		if (stats->letter > 'A')
			--stats->letter;
		stats->pos = pos;
		ft_add_tetrimino(tetrimino, map, stats, CLEAR);
	}
	return ((pos > ft_pow(stats->size, 2) - ft_sum_content(tetrimino) - 1) ?
			FAILURE : ft_resolve(tetrimino, map, stats, pos + 1));
}
