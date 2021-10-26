/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:25:56 by bifrah            #+#    #+#             */
/*   Updated: 2021/06/17 18:08:16 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;

	if (!lst || !f)
		return (NULL);
	newlst = ft_lstnew(NULL);
	if (!newlst)
	{
		ft_lstclear(&newlst, del);
		return (NULL);
	}
	if (lst)
		newlst->next = ft_lstmap(lst->next, f, del);
	newlst->content = f(lst->content);
	return (newlst);
}
