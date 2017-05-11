/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:23:49 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/05/09 23:41:31 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void *content, size_t content_size, char letter)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		new->letter = 0;
	}
	else
	{
		new->content = ft_memcpy(ft_memalloc(content_size),
				content, content_size);
		new->content_size = content_size;
		new->letter = letter;
	}
	new->next = NULL;
	return (new);
}
