/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 15:41:13 by dnetto            #+#    #+#             */
/*   Updated: 2017/05/03 09:21:53 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int start;
	int l;

	if (s == NULL)
		return (NULL);
	start = 0;
	l = ft_strlen((char*)s) - 1;
	while (ft_isesp(((char*)s)[start]))
		start++;
	while (ft_isesp(((char*)s)[l]) && l > 0)
		l--;
	return ((s[start]) ? ft_strsub(s, start, l - start + 1) : ft_strdup("\0"));
}
