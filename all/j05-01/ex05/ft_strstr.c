/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 03:45:58 by dnetto            #+#    #+#             */
/*   Updated: 2017/03/21 08:04:50 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*tmp;
	char	*tmpa;
	char	*tmpb;

	if (*to_find == 0)
		return (str);
	tmp = str;
	while (*tmp)
	{
		tmpa = tmp;
		tmpb = to_find;
		while (*tmp && *tmpb && *tmp == *tmpb)
		{
			++tmp;
			++tmpb;
		}
		if (*tmpb == 0)
			return (tmpa);
		tmp = tmpa + 1;
	}
	return (0);
}
