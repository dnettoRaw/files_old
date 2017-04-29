/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 00:38:01 by dnetto            #+#    #+#             */
/*   Updated: 2017/03/21 08:08:27 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	int i;

	i = -1;
	if (str[i + 1] == '\0')
		return (1);
	while (str[++i])
		if (!(str[i] >= 32 && str[i] <= 126))
			return (0);
	return (1);
}