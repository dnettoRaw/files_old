/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 14:13:56 by dnetto            #+#    #+#             */
/*   Updated: 2017/03/30 08:48:42 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_par.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int      main(int as, char **a)
{
	ft_show_tab(ft_param_to_tab(as -1, a + 1));
	return (0);
}
