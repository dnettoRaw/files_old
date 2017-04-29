/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 02:18:07 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/29 15:38:06 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[++i - 1] && i - 1 < n)
		dest[i - 1] = src[i - 1];
	i--;
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
