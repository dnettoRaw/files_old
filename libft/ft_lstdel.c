/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 01:59:40 by dnetto            #+#    #+#             */
/*   Updated: 2017/04/26 02:30:22 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nextlst;
	t_list	*templst;

	templst = *alst;
	while (templst)
	{
		nextlst = templst->next;
		del(templst->content, templst->content_size);
		free(templst);
		templst = nextlst;
	}
	*alst = NULL;
}
