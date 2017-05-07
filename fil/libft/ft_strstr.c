/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 19:52:23 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/04/19 18:55:14 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char			*ft_strstr(const char *haystack, const char *needle)
{
	const char	*n;
	const char	*h;

	n = needle;
	if (*needle == 0)
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *n)
		{
			h = haystack;
			while (1)
			{
				if (*n == 0)
					return ((char *)haystack);
				if (*h++ != *n++)
					break ;
			}
		}
		++haystack;
		n = needle;
	}
	return (NULL);
}
