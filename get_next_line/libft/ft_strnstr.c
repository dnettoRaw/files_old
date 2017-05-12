/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:21:14 by dnetto            #+#    #+#             */
/*   Updated: 2017/05/03 06:53:05 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, const char *to_find, size_t n)
{
	char	*fin;
	size_t	len;
	size_t	i;

	len = ft_strlen((char *)to_find);
	i = 0;
	if (len == 0)
		return (str);
	if (ft_strcmp(str, "") == 0)
		return (NULL);
	fin = ((str + n) - (len - 1));
	while (str[i] && &str[i] < fin && i < n)
	{
		if (ft_strncmp(&str[i], (char *)to_find, len) == 0)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
