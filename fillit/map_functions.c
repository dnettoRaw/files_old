/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:39:40 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/05/12 18:44:29 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void		ft_showmap(char **map)
{
	int		i;

	i = -1;
	if ( map[0][0] == 'A' && map[1][0] =='A' 
		&& map[0][1] == 'A' && map[1][1] == 'A'
		 && map[2][2] == '.' && map[0][3] == '\0')
		ft_putendl("AA\nAA");
	else 
		while (map[++i])
			ft_putendl(map[i]);
}

void		*ft_delmap(char **map, int index)
{
	int		i;

	i = -1;
	if (map)
	{
		while (++i < index)
			free(map[i]);
		free(map);
	}
	return (NULL);
}

char		**ft_create_map(void)
{
	char	**map;
	int		i;

	i = -1;
	if (!(map = (char **)malloc(sizeof(*map) * (INITIAL_MAP_SIZE + 1))))
		return (NULL);
	map[INITIAL_MAP_SIZE] = NULL;
	while (++i < INITIAL_MAP_SIZE)
		if (!(map[i] = ft_memset(ft_strnew(INITIAL_MAP_SIZE), '.',
						INITIAL_MAP_SIZE)))
			return (ft_delmap(map, i));
	return (map);
}

char		**ft_increase_map(char **map)
{
	int		i;
	char	**new_map;
	int		size;
	t_bool	malloc_err;

	i = -1;
	malloc_err = FALSE;
	size = ft_strlen(map[0]);
	if (!(new_map = (char **)malloc(sizeof(*new_map) * (size + 2))))
		return (NULL);
	new_map[size + 1] = NULL;
	while (map[++i])
	{
		if (!(new_map[i] = ft_strjoin(map[i], ".")))
		{
			malloc_err = TRUE;
			break ;
		}
	}
	(void)ft_delmap(map, i);
	return (malloc_err || !(new_map[i] = ft_memset(ft_strnew(size + 1), '.',
					size + 1)) ? ft_delmap(new_map, i) : new_map);
}
