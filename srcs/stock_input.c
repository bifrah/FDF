/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:33:53 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/26 13:52:26 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_stock_input(char **argv, t_dlist *list)
{
	t_param	param;
	char	**dest;

	param.fd = open(argv[1], O_RDONLY);
	param.line = 0;
	param.tmp = get_next_line(param.fd);
	while ((param.tmp != NULL))
	{
		param.i = -1;
		dest = ft_split(param.tmp, ' ');
		ft_dlistaddt(&list);
		list->p_tail->x = (int *)malloc(sizeof(int) * (ptrstrlen(dest)));
		if (!(list->p_tail->x))
			return (MALLOC_ERROR);
		while (dest[++param.i])
			list->p_tail->x[param.i] = ft_atoi(dest[param.i]);
		list->p_tail->y = param.line;
		ft_free(&param.tmp, &dest);
		param.line++;
		param.tmp = get_next_line(param.fd);
	}
	ft_free(&param.tmp, &dest);
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