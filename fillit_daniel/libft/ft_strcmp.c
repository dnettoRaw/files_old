/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:52:59 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/13 00:17:51 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*tmp;
	unsigned char	*tmp1;

	i = 0;
	tmp = (unsigned char *)s1;
	tmp1 = (unsigned char *)s2;
	while (tmp[i] && tmp1[i] && tmp[i] == tmp1[i])
		i++;
	return (tmp[i] - tmp1[i]);
}
