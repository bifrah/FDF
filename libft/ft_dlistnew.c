/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:58:50 by mtordjma          #+#    #+#             */
/*   Updated: 2021/11/06 14:45:21 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
