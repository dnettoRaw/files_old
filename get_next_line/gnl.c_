/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:36:16 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/11 16:23:25 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#define BUF_SIZE  10

int		ft_strlen(char *str, int i)
{
	return ((str[++i]) ? ft_strlen(str, i) : i);
}

void	ft_putstr(char *str, int fd)
{
	if (fd < 0)
		return ;
	write(fd, str, ft_strlen(str, -1));
}

void	readwrite(char *str)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return ;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		ft_putstr(buf, 1);
	}
	if (ret == -1)
		return ;
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc == 1)
			ft_putstr("File name missing.\n", 1);
		else if (argc > 2)
			ft_putstr("Too many arguments.\n", 1);
		return (0);
	}
	readwrite(argv[1]);
	return (0);
}
