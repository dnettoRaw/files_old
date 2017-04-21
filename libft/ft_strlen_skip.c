/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_skip.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 00:17:45 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/22 01:04:55 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_skip(char *str, char skip)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (str[++i])
		if (!(str[i] == skip))
		   j++;
	return (j);
}

int 	ft_strlen_stp(char str)
{

}

int		ft_strlen_tool(char *str, char c, int nbr)
{
	if (nbr == 0)
		return(ft_strlen(str));
	if (nbr == 1)
		return(ft_strlen_skip(str, c));
	if (nbr )
}
