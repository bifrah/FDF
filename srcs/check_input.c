/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:03:54 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/18 03:22:21 by bifrah           ###   ########.fr       */
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

int	ft_lineisnum(char **dest)
{
	t_index	index;

	index.j = -1;
	index.i = 0;
	if (dest == NULL)
		return (0);
	while (dest[++index.j])
	{	
		if (dest[index.j][0] == '-' && index.i == 0)
		{
			index.i = 1;
			if (ft_isdigit(dest[index.j][index.i]) == 0)
				return (-1);
		}
		while (dest[index.j][index.i] && dest[index.j][index.i] != '\n')
		{
			if (ft_isdigit(dest[index.j][index.i]) == 0)
				return (-1);
			index.i++;
		}
		if (index.i > 5)
			return (-1);
		printf("dest[%d] = %s\n", index.j, dest[index.j]);
		index.i = 0;
	}
	return (0);
}

int	ptrstrlen(char **dest)
{
	int	j;

	j = 0;
	while (dest[j])
		j++;
	return (j);
}

int	ft_check_map(int fd)
{
	char	**dest;
	t_check	check;

	check.line = 0;
	check.tmp = get_next_line(fd);
	while ((check.tmp != NULL && check.tmp[0]))
	{
		dest = ft_split(check.tmp, ' ');
		check.len_tmp = ptrstrlen(dest);
		if (check.line == 0)
			check.len_ref = check.len_tmp;
		if (check.len_tmp != check.len_ref || ft_lineisnum(dest) == -1)
			return (MAP_ERROR);
		free(check.tmp);
		free(dest);
		check.line++;
		check.tmp = get_next_line(fd);
	}
	if (check.tmp == NULL)
		return (0);
	return (-1);
}

/*
Lire ligne par ligne (et stocker chaques lignes)
Verifier si :
- (1) Pas vide
- (2) Chaque lignes a le meme nombre de caractere
- (3) Est compose de "nb  nb  nb  nb..."
*/