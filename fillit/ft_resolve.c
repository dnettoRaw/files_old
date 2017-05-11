/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 20:47:33 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/05/10 16:38:30 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Found_empty_block is testing if the row'th next cell within the map is empty
** and also if the representation of the tetrimino is coherent.
** Basically, we check if any step (to access the position of the next cell
** of our tetrimino) different than 1 triggers a line change and the opposite.
*/

static t_bool	found_empty_block(t_list *tetrimino, char **map,
		int *stats, int pos)
{
	int			line;
	int			col;
	int			*comb;
	int			row;

	comb = (int *)tetrimino->content;
	row = -1;
	while (++row < CONTENT_SIZE)
	{
		line = pos / stats[SIZE];
		pos += (comb[row] == -2 ? 1 : comb[row]);
		if ((comb[row] != 1 && line == pos / stats[SIZE])
			|| (comb[row] == 1 && line != pos / stats[SIZE]))
			return (FALSE);
		line = pos / stats[SIZE];
		col = pos % stats[SIZE];
		if (map[line][col] != EMPTY)
			return (FALSE);
	}
	return (TRUE);
}

/*
** The field stats[POS] is used to circumvent the variables limitation.
*/

static void		ft_add_tetrimino(t_list *tetrimino, char **map,
		int *stats, int mode)
{
	int			line;
	int			col;
	int			*p;
	int			row;

	row = -1;
	line = stats[POS] / stats[SIZE];
	col = stats[POS] % stats[SIZE];
	map[line][col] = (mode == FILL ? tetrimino->letter : EMPTY);
	p = (int *)tetrimino->content;
	while (++row < CONTENT_SIZE)
	{
		stats[POS] += (p[row] == -2 ? 1 : p[row]);
		line = stats[POS] / stats[SIZE];
		col = stats[POS] % stats[SIZE];
		map[line][col] = (mode == FILL ? tetrimino->letter : EMPTY);
	}
}

static int		ft_sum_content(t_list *tetrimino)
{
	int			*comb;
	int			row;
	int			res;

	row = -1;
	res = 0;
	comb = (int *)tetrimino->content;
	while (++row < CONTENT_SIZE)
		res += (comb[row] == -2 ? 1 : comb[row]);
	return (res);
}

static t_bool	valid_pos(t_list *tetrimino, char **map,
		int *stats, int pos)
{
	int			line;
	int			col;

	line = pos / stats[SIZE];
	col = pos % stats[SIZE];
	return ((pos <= ft_pow(stats[SIZE], 2) - ft_sum_content(tetrimino) - 1)
			&& map[line][col] == EMPTY ? TRUE : FALSE);
}

int				ft_resolve(t_list *tetrimino, char **map, int *stats,
		int pos)
{
	if (!tetrimino)
		return (SUCCESS);
	if (valid_pos(tetrimino, map, stats, pos) &&
			found_empty_block(tetrimino, map, stats, pos))
	{
		stats[POS] = pos;
		ft_add_tetrimino(tetrimino, map, stats, FILL);
		if (ft_resolve(tetrimino->next, map, stats, 0) == SUCCESS)
			return (SUCCESS);
		stats[POS] = pos;
		ft_add_tetrimino(tetrimino, map, stats, CLEAR);
	}
	return ((pos > ft_pow(stats[SIZE], 2) - ft_sum_content(tetrimino) - 1) ?
			FAILURE : ft_resolve(tetrimino, map, stats, pos + 1));
}
