/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:03:54 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/22 18:47:25 by bifrah           ###   ########.fr       */
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
		{
			ft_free(&check.tmp, &dest);
			return (MAP_ERROR);
		}
		ft_free(&check.tmp, &dest);
		check.line++; 
		check.tmp = get_next_line(fd); 
	}
	ft_free(&check.tmp, NULL);
	if (check.tmp == NULL && check.line != 0)
		return (0);
	return (MAP_ERROR);
}

/*
Lire ligne par ligne (et stocker chaques lignes)
Verifier si :
- (1) Pas vide
- (2) Chaque lignes a le meme nombre de caractere
- (3) Est compose de "nb  nb  nb  nb..."
*/
// 1 0 1 => ["1", "0", "1\n", "\0"]
