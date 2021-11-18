/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:33:53 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/18 03:55:18 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    ft_stock_input(int fd, t_dlist *list)
{
	char	**dest;
	char	*tmp;
	int		i;

	i = -1;
	tmp = get_next_line(fd);
	while ((tmp != NULL && tmp[0]))
	{
		dest = ft_split(tmp, ' ');
		while (dest[++i])
		{
			ft_dlistaddt(&list);
			list->p_tail->data = ft_strdup(dest[i]);	
		}
		free(tmp);
		free(dest);
		tmp = get_next_line(fd);
	}
	return (-1);
}



/*
Tout est check, il ne reste plus qu'a tout stocker.
1- Je creer un tmp auquel j'assigne gnl
2- Dans **dest j'assigne chaque nombres dans une case
3- Je creer et j'assigne pour chaques case de dest un nouvel element de list pour le stocker dans data
4- Je free tmp et dest
5- Je recommence pour chaques lignes.

TO DO :
J'aimerais savoir quand je change de ligne afin que mon draw le sache aussi.
A voir si Bresenham algo need de le savoir.
*/