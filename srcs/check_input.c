/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:03:54 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/13 18:32:00 by bifrah           ###   ########.fr       */
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
	while ((tmp = get_next_line(fd))) // (1) check si vide 
	{
		if (line > 0) // (2) check len chaque ligne identique
		{
			len_act = ft_strlen(tmp);
			if (len_tmp != len_act)
			{
				return (MAP_ERROR);
			}
			printf("len avant : %d\nlen actuel : %d\n", len_tmp, len_act);
			len_tmp = len_act;
		}
		while (tmp[i] != '\n')	// (3) check caracteres de chaque ligne
		{
			if (tmp[i] != '\n' && ft_isdigit(tmp[i]) == 0)
			{
				write(1, "ERROR 1 HERE\n", 13);
				ft_dlistdel(&list);
				return (MAP_ERROR);
			}
			i++;
			if (tmp[i] != '\n' && ft_checkspace(tmp[i]) == 0)
			{
				write(1, "ERROR 2 HERE\n", 13);
				ft_dlistdel(&list);
				return (MAP_ERROR);
			}
			i++;
		}
		ft_dlistaddt(&list);
		list->p_tail->data = ft_strdup(tmp); //MALLOC GAFFE FDP
		line++;
	}
	return (LINE_IN_DATA);
}

/*
Lire ligne par ligne (et stocker chaques lignes)
Verifier si :
- (1) Pas vide
- (2) Chaque lignes a le meme nombre de caractere
- (3) Est compose de "nb  nb  nb  nb..."
- Les nb soient assez proche pour entrer dans la fenetre 1920*1080
- La map entre entierement dans la fenetre
*/