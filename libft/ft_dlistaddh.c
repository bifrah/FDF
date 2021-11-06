/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistaddh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:56:18 by mtordjma          #+#    #+#             */
/*   Updated: 2021/11/06 14:45:07 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dnode	*ft_dlistaddh(t_dlist **p_list)
{
	t_dnode *p_newnode;

	if ((*p_list) == NULL)
		return (NULL);
	if (!(p_newnode = (t_dnode *)malloc(sizeof(*p_newnode))))
		return (NULL);
	p_newnode->p_prev = NULL;
	if ((*p_list)->p_tail == NULL)
	{
		p_newnode->p_next = NULL;
		(*p_list)->p_head = p_newnode;
		(*p_list)->p_tail = p_newnode;
	}
	else
	{
		(*p_list)->p_head->p_prev = p_newnode;
		p_newnode->p_next = (*p_list)->p_head;
		(*p_list)->p_head = p_newnode;
	}
	(*p_list)->length++;
	return (p_newnode);
}
