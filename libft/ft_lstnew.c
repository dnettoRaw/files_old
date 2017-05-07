/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 16:29:18 by dnetto            #+#    #+#             */
/*   Updated: 2017/05/03 08:48:06 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*n;

	if (!(n = (t_list*)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		n->content = NULL;
		n->content_size = 0;
	}
	else
	{
		n->content = ft_strdup((char*)content);
		n->content_size = content_size;
	}
	n->next = NULL;
	return (n);
}
