/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 18:17:18 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/05/04 18:01:55 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_get_height(t_list *tetrimino)
{
	int	i;
	int	height;
	int	*p;

	i = -1;
	height = 1;
	p = (int *)tetrimino->content;
	while (++i < CONTENT_SIZE)
		if (p[i] > 1)
			++height;
	return (height);
}

int		ft_get_width(t_list *tetrimino)
{
	int	i;
	int	width;
	int	*p;

	i = -1;
	width = 1;
	p = (int *)tetrimino->content;
	while (++i < CONTENT_SIZE)
		if (p[i] == 1)
			++width;
	return (width);
}
