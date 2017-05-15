/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:36:16 by dnetto            #+#    #+#             */
/*   Updated: 2017/05/15 19:27:31 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_check_static(char **static_, char **line)
{
	char		*tmp;

	tmp = NULL;
	if (*static_)
	{
		if ((tmp = ft_strchr((const char*)*static_, '\n')))
		{
			*line = ft_strsub((const char*)*static_, 0, tmp - *static_);
			ft_memmove(*static_, tmp + 1, ft_strlen(tmp));
			return (1);
		}
	}
	return (0);
}

static int		ft_read(int fd, char **static_, char **str)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = *static_;
		if (*static_)
		{
			*static_ = ft_strjoin((char const*)tmp, (char const*)buf);
			free(tmp);
		}
		else
			*static_ = ft_strdup((const char*)buf);
		if (ft_check_static(static_, str))
			return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*gnl[FD_VL];
	int			res;
	char		test_read[BUFF_SIZE];

	if (fd < 0 || !line || (read(fd, test_read, 0) < 0))
		return (-1);
	if (gnl[fd] && ft_check_static(&gnl[fd], line))
		return (1);
	if ((res = ft_read(fd, &gnl[fd], line)) != 0)
		return (res);
	if (gnl[fd] == NULL || gnl[fd][0] == '\0')
		return (0);
	*line = gnl[fd];
	gnl[fd] = NULL;
	return (1);
}

/*
**					commentaires
**
**				{check si je suis a la fin de ma ligne}
**
**	static int		ft_check_static(char **static_, char **line)
**	{
**		char		*tmp;
**
**		tmp = NULL;
**		if (*static_)
**		{
**			if ((tmp = ft_strchr((const char*)*static_, '\n')))
**			{
**				*line = ft_strsub((const char*)*static_, 0, tmp - *static_);
**				ft_memmove(*static_, tmp + 1, ft_strlen(tmp));
**							// memmove de tmp sur mon static
**				return (1);
**			}
**		}
**		return (0);
**	}
**
**
**				{ read }
**
**	static int		ft_read(int fd, char **static_, char **str)
**	{
**		int			ret;
**		char		buf[BUFF_SIZE + 1];
**					// je gere pas le cas d'un buffer de 10 000 000
**		char		*tmp;
**
**		while ((ret = read(fd, buf, BUFF_SIZE)))
**		{
**			buf[ret] = '\0';
**			tmp = *static_;
**			if (*static_)
**			{
**				*static_ = ft_strjoin((char const*)tmp, (char const*)buf);
**				free(tmp); // pour que je puise garder les anciennes lines
**			}
**			else
**				*static_ = ft_strdup((const char*)buf);
**						// pour ma premiere line
**			if (ft_check_static(static_, str))
**				return (1);
**		}
**		return (0);
**	}
**
**
**	int				get_next_line(const int fd, char **line)
**	{
**		static char	*gnl[FD_VL];
**	// tres beau tableau de char mdr(ah changer ça pour une liste dans l'avenir)
**		int			res;
**		char		test_read[BUFF_SIZE];
**	//pour tester si le fd est bien ouvert pour la lecture
**
**		if (fd < 0 || !line || (read(fd, test_read, 0) < 0))
**			return (-1);
**		if (gnl[fd] && ft_check_static(&gnl[fd], line))
**			return (1);
**		res = ft_read(fd, &gnl[fd], line); // read returnera un int sur res
**		if (res != 0)
**			return (res);
**		if (gnl[fd] == NULL || gnl[fd][0] == '\0')
**			return (0); // fin des testes logics sur res
**		*line = gnl[fd];
**		gnl[fd] = NULL;
**		return (1);
**	}
*/
