/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtordjma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:58:50 by mtordjma          #+#    #+#             */
/*   Updated: 2019/01/30 16:59:40 by mtordjma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

t_dlist	*ft_dlistnew(void)
{
	t_dlist *p_newlst;

	if (!(p_newlst = (t_dlist *)malloc(sizeof(*p_newlst))))
		return (NULL);
	if (p_newlst != NULL)
	{
		p_newlst->length = 0;
		p_newlst->p_head = NULL;
		p_newlst->p_tail = NULL;
	}
	return (p_newlst);
}
