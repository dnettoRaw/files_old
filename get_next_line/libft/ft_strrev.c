/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 08:11:48 by dnetto            #+#    #+#             */
/*   Updated: 2017/05/02 16:11:30 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *a)
{
	int		i;
	int		c;
	char	*res;

	c = ft_strlen(a);
	i = 0;
	if ((res = (char*)malloc((sizeof(char) * (c + 1)))) == NULL)
		return (NULL);
	c--;
	while (c + 1 > 0)
		res[i++] = a[c--];
	return (res);
}
