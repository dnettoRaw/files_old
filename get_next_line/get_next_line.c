/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:36:16 by dnetto            #+#    #+#             */
/*   Updated: 2017/05/12 20:31:37 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

int	get_next_line(const int fd, char **line)
{
	static	char	*gnl;
	int		ret;
	char		*buff;
	
	gnl = NULL;
	buff = ft_strnew(BUFF_SIZE);
	if (fd == -1)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{

		buff[ret] = '\0';
		gnl = ft_strjoin(gnl, buff);
		ft_putstr("\n======\nbuff =\n");
		ft_putstr(buff);
	}
	free(buff);
	buff = NULL;
		ft_putendl("teste du while 4");
	if (ret == -1)
		return (-1);
	*line = ft_strdup(gnl);
		ft_putendl("teste du while 5");
	free (gnl);
		ft_putendl("teste du while 6");
	gnl = NULL;
		ft_putendl("teste du while 7");
	return (1);
}
