/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:03:54 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/09 16:49:18 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_check_input(int argc, char **argv)
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
	char	*tmp;
	int		line;
	int		i;
	int		len_tmp;
	int		len_act;

	line = 0;
	i = 0;
	while ((tmp = get_next_line(fd))) //check toutes erreur possible et free si error
	{
		len_act = ft_strlen(tmp);
		if (line > 0 && len_tmp != len_act)
			return (MAP_ERROR);
		len_tmp = len_act;
		while (tmp[i])
		{
			if (fpclassify((float)tmp[i]) != FP_NORMAL
				|| fpclassify((float)tmp[i]) != FP_ZERO)
			{
				ft_dlistdel(&list);
				return (MAP_ERROR);
			}
			i++;
			if (tmp[i] && ft_checkspace(tmp[i]) == 0)
			{
				ft_dlistdel(&list);
				return (MAP_ERROR);
			}
			i++;
		}
		ft_dlistaddt(&list);
		list->p_tail->data = ft_strdup(tmp); //MALLOC GAFFE FDP
		line++;
	}
	return (0);
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