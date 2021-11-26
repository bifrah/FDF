/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:59:48 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/26 14:12:17 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dlistdel(t_dlist **p_list, int errcode)
{
	t_dnode	*p_temp;
	t_dnode	*p_del;

	if (*p_list != NULL)
	{
		p_temp = (*p_list)->p_head;
		while (p_temp != NULL)
		{
			p_del = p_temp;
			p_temp = p_temp->p_next;
			if (p_del->x)
				free(p_del->x);
			free(p_del);
		}
		free(*p_list);
		*p_list = NULL;
	}
	return (errcode);
}
