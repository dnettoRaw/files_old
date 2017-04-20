/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:24:06 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/14 20:31:15 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	ft_strlcat(char *dest, char *src, int nb)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (dest[++i]);
	while (src[j] && j < nb)
		dest[i++] = src[j++];
	dest[i] = '\0';
	j = 0;
	while (src[j++]);
	return (i + nb);
}*/
// v2.0 
/*int	ft_strlcat(char *dest, char *src, int nb)
{
	int i;
	int j;

	i = ft_strlen(dest);
	j = -1;
	while (src[++j] && (i + j < nb - 1))
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	if (src[j])
		while (src[++j]);
	return (j + (i < nb ? i : nb));
}*/
// v3.0
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
