/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:24:06 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/25 18:30:57 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, char *src, int nb)
{
	int ld;
	int ls;

	ld = ft_strlen(dest);
	ls = ft_strlen(src);
	if (ld >= nb)
		return (ls + nb);
	ft_strncat(dest, src, (ls < ld - nb ? ls + 1 : nb - ld));
	dest[nb - 1] = '\0';
	return (ld + ls);
}
