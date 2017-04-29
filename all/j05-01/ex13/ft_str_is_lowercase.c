/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 23:41:50 by dnetto            #+#    #+#             */
/*   Updated: 2017/03/21 08:07:27 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_lowercase(char *str)
{
	int i;

	i = -1;
	if (str[i + 1] == '\0')
		return (1);
	while (str[++i])
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			return (0);
	return (1);
}