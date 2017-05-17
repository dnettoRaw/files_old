/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 12:33:45 by dnetto            #+#    #+#             */
/*   Updated: 2017/05/17 12:01:47 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	char    *line = NULL;
	int     fd[ac];
	int     ret = 0;

	if (ac > 1)
	{
		int i = 0;
		while (i < ac - 1)
		{
			if ((fd[i] = open(av[i + 1], O_RDONLY)) > 0)
			{
				printf("\033[32mfile = %s \ti=%d | ac=%d\033[0m\n",av[i + 1], i, ac);
				while ((ret = get_next_line(fd[i], &line)) > 0) {
					puts(line);
					free(line);
				}
				if (ret < 0){
					printf("/\e[1;31m!\e[0m\\ error reading '%s'\n", av[1]);
				}
				close(fd[i]);
			}
			else {
				printf("/\e[1;31m!\e[0m\\ error opening '%s'\n", av[1]);
			}
			i++;
		}
	}
	else
		while ((ret = get_next_line(0, &line)) > 0){
			puts(line);
			free(line);
		}
	return (0);
}
