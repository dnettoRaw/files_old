/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:41:20 by dnetto            #+#    #+#             */
/*   Updated: 2017/05/03 09:25:59 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mmalloc;

	mmalloc = (void*)malloc(sizeof(void*) * size);
	return (mmalloc == NULL ? NULL : ft_memset(mmalloc, 0, size));
}
