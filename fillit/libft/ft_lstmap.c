/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:26:19 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/05/09 23:41:53 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem))
{
	t_list	*lstmap;

	if (!list || !f)
		return (NULL);
	lstmap = NULL;
	while (list)
	{
		ft_lstpush(&lstmap, f(ft_lstnew(list->content, list->content_size, 0)));
		list = list->next;
	}
	return (lstmap);
}
