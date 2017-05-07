/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 21:17:51 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/05/01 20:24:25 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <stdlib.h>

static void	wrong_event(t_list **alst, int fd, char *err_msg)
{
	if (*alst)
		ft_lstdel(alst, ft_delcontent);
	close(fd);
	ft_error(err_msg);
}

static void	first_read(t_list **alst, int fd)
{
	int		*comb;
	char	buf[BUF_SIZE];

	ft_bzero(buf, BUF_SIZE);
	(void)read(fd, buf, BUF_SIZE - 2);
	if (!(comb = ft_check_buf(buf, TRUE)))
		wrong_event(alst, fd, ERR);
	ft_lstpush(alst, ft_lstnew(comb, CONTENT_SIZE * sizeof(int),
				FT_LSTNEW_ALLOC));
	free(comb);
}

t_list		*ft_get_tetriminoes(int fd)
{
	t_list	*tetriminoes;
	char	buf[BUF_SIZE];
	int		*comb;

	ft_bzero(buf, BUF_SIZE);
	tetriminoes = NULL;
	first_read(&tetriminoes, fd);
	while (read(fd, buf, BUF_SIZE - 1))
	{
		if (!(comb = ft_check_buf(buf, FALSE)))
			wrong_event(&tetriminoes, fd, ERR);
		ft_lstpush(&tetriminoes, ft_lstnew(comb, CONTENT_SIZE * sizeof(int),
					FT_LSTNEW_ALLOC));
		ft_bzero(buf, BUF_SIZE);
		free(comb);
	}
	if (ft_lstsize(tetriminoes) > MAX_PIECES)
		wrong_event(&tetriminoes, fd, ERR);
	close(fd);
	return (tetriminoes);
}
