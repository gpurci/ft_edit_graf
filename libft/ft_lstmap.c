/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpurci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:00:06 by gpurci            #+#    #+#             */
/*   Updated: 2016/11/21 16:23:55 by gpurci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*beg;
	t_list	*ap;

	if (!lst || !f)
		return (0);
	beg = f(lst);
	ap = beg;
	while (lst->next)
	{
		lst = lst->next;
		ap->next = f(lst);
		ap = ap->next;
	}
	return (beg);
}
