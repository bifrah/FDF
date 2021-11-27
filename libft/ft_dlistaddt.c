/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistaddt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:04:16 by mtordjma          #+#    #+#             */
/*   Updated: 2021/11/27 14:45:27 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dnode	*ft_dlistaddt(t_dlist **p_list)
{
	t_dnode	*p_newnode;

	p_newnode = (t_dnode *)malloc(sizeof(*p_newnode));
	if (!p_newnode)
		return (NULL);
	p_newnode->p_next = NULL;
	if ((*p_list) != NULL)
	{
		if ((*p_list)->p_tail == NULL)
		{
			p_newnode->p_prev = NULL;
			(*p_list)->p_head = p_newnode;
			(*p_list)->p_tail = p_newnode;
		}
		else
		{
			(*p_list)->p_tail->p_next = p_newnode;
			p_newnode->p_prev = (*p_list)->p_tail;
			(*p_list)->p_tail = p_newnode;
		}
		(*p_list)->length++;
	}
	return (p_newnode);
}
