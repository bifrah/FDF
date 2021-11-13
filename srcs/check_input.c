/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:03:54 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/13 21:45:12 by bifrah           ###   ########.fr       */
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
	int		len_old;
	int		len_act;

	line = 0;
	i = 0;
	while ((tmp = get_next_line(fd))) // (1) check si vide
	{
		len_act = ft_strlen(tmp);
		if (line == 0) // (2) check len chaque ligne identique
			len_old = len_act;
		if (len_old != len_act)
			return (MAP_ERROR);
		while (tmp[i] != '\n')	// (3) check caracteres de chaque ligne
		{
			if (tmp[i] && ft_isdigit(tmp[i]) == 0)
			{
				//write(1, "ERROR : Number\n", 15);
				ft_dlistdel(&list);
				return (MAP_ERROR);
			}
			i++;
			if (tmp[i] == '\n')
			{
				ft_dlistaddt(&list);
				list->p_tail->data = ft_strdup(tmp); //MALLOC GAFFE FDP
				printf("data : %s\n", list->p_tail->data);
				line++;
				return (LINE_IN_DATA);
			}
			if (tmp[i] && ft_checkspace(tmp[i]) == 0)
			{
				//write(1, "ERROR : Space\n", 14);
				ft_dlistdel(&list);
				return (MAP_ERROR);
			}
			i++;
		}
	}
	return (LINE_IN_DATA);
}

/*
Lire ligne par ligne (et stocker chaques lignes)
Verifier si :
- (1) Pas vide
- (2) Chaque lignes a le meme nombre de caractere
- (3) Est compose de "nb  nb  nb  nb..."
- La map entre entierement dans la fenetre
*/