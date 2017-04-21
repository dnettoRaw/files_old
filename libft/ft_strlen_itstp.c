/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_itstp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 23:13:45 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/22 00:14:57 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_itstp(char *str, char stp)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == stp)
			return (i);
	return (i);
}
