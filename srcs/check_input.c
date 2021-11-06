/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:03:54 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/06 15:17:12 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int ft_check_input(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (NB_PARAM_ERROR);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (INPUT_ERROR);
	return (fd);
}

int	ft_check_map(int fd, t_dlist *list)
{
	char *tmp;
	int		line;
	int i;

	line = 0;
	i = 0;
	while (tmp != NULL)
	{
		tmp = get_next_line(fd);
		ft_dlistaddt(&list);
		list->p_tail = ft_stock_input(/*ligne 1 puis 2 etc...*/);
		if (fpclassify((float)str[i]) != FP_NORMAL
			|| fpclassify((float)str[i]) != FP_ZERO)
			return (MAP_ERROR);
		i++;
		if (checkspace(str[i]) != 32)
			return (MAP_ERROR);
		line++;
	}
}


/*
Lire ligne par ligne (et stocker chaques lignes)
Verifier si :
- Pas vide
- Chaque lignes a le meme nombre de caractere
- Est compose de "nb nb nb nb..."
- Les nb soient assez proche pour entrer dans la fenetre 1920*1080
- La map entre entierement dans la fenetre
*/