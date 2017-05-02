/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 01:28:22 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/29 14:45:14 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main(int i,char **argv)
{
	if (i < 2)
		return (0);
	i = 1;
	char *res;

	res = ft_convertbase((unsigned int)ft_atoi(argv[1]), ft_atoi(argv[2]));
	printf("res = %s\n", res);
	free(res);
	return(0);
}
