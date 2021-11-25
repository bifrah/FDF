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

void    ft_stock_input(char **argv, t_dlist *list)
{
	int		fd;
	char	**dest;
	char	*tmp;
	int		i;
	int		line;

	fd = open(argv[1], O_RDONLY);
	i = -1;
	line = 0;
	tmp = get_next_line(fd);
	printf("tmp : %s\n", tmp);
	while ((tmp != NULL))
	{
		ft_dlistaddt(&list);
		dest = ft_split(tmp, ' ');
		while (dest[++i])
		{
			list->p_tail->x[i] = ft_atoi(dest[i]);
			list->p_tail->y = line;
			printf("line = %d\ndata = %d\n", list->p_tail->y, list->p_tail->x[i]);
		}		
		ft_free(&tmp, &dest);
		line++;
		tmp = get_next_line(fd);
	}
	return ;
}

/*
Tout est check, il ne reste plus qu'a tout stocker.
1- Je creer un tmp auquel j'assigne gnl
2- Dans **dest j'assigne chaque nombres dans une case
3- Je creer et j'assigne pour chaques case de dest a une case de *x (*x = data)
4- Je free tmp et dest
5- Je recommence pour chaques lignes.
*/