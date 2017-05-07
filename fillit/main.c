/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 17:44:34 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/05/07 20:59:52 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int				main(int ac, char **av)
{
	int			fd;
	t_list		*tetriminoes;
	char		**map;
	t_map_stats	stats;
	int			i;

	if (ac != 2)
		ft_error(USAGE);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error(ERR);
	tetriminoes = ft_get_tetriminoes(fd);
	stats.size = MAP_SIZE;
	stats.letter = 'A';
	stats.pos = 0;
	i = -1;
	map = ft_create_map();
	while (ft_resolve(tetriminoes, map, &stats, 0) != SUCCESS)
	{
		ft_lstincrement(tetriminoes, 1);
		++stats.size;
		map = ft_increase_map(map);
	};
	ft_showmap(map);
	ft_delmap(map, ft_strlen(map[0]));
	ft_lstdel(&tetriminoes, ft_delcontent);
	return (0);
}
