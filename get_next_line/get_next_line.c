/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:36:16 by dnetto            #+#    #+#             */
/*   Updated: 2017/05/13 22:43:36 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

static int	ft_check_static(char **stock, char **line)
{
	char  *tmp;
	
	tmp = NULL;
	if (*stock)
	{
		if ((tmp = ft_strchr(((const char*)*stock), '\n')))
		{
			*line = ft_strsub((const char*)*stock, 0, tmp - *stock);
			ft_memmove(*stock, tmp + 1, ft_strlen(tmp));
			return (1);
		}
	}
	return (0);
}

static int	ft_read(int fd, char **stock, char **str)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = *stock;
		if (*stock)
		{
			*stock = ft_strjoin((char const*)tmp, (char const*)buf);
			free(tmp);
		}
		else
			*stock = ft_strdup((const char*)buf);
		if (ft_check_static(stock, str))
			return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*gnl[FD_SETSIZE];
	int			res;
	char		test_read[BUFF_SIZE];

	if (fd < 0 || !line ||( read(fd, test_read, 0) < 0))
	   return (-1);
	if (gnl[fd] && ft_check_static(&gnl[fd], line))
		return (1);
	res = ft_read(fd, &gnl[fd], line);
	if (res != 0)
		return (res);
	if (gnl[fd] == NULL || gnl[fd][0] == '\0')
		return (0);
	*line = gnl[fd];
	gnl[fd] = NULL;
	return (1);
}
