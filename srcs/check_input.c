/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:03:54 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/13 23:59:48 by bifrah           ###   ########.fr       */
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

int	ft_lineisnum(char **dest)	//dest[0] = -20; dest[1] = 1; dest[2] = 2\n; dest[3] = NULL;
{
	int	j;						//dest[0][0] = -
	int	i;						//dest[0][1] = 2
								//dest[0][2] = 0
	j = 0;
	i = 0;
	if (dest == NULL)
		return (0);
	while (dest[j])
	{	
		if (dest[j][0] == '-' && i == 0)
			i = 1;
		while (dest[j][i])
		{
			if (ft_isdigit(dest[j][i]) == 0)
				return (-1);
			i++;
		}
		if(i > 5)
			return (-1);
		printf("dest[%d] = %s\n", j, dest[j]);
		j++;
		i = 0;
	}
	return (0);
}

int	ft_check_map(int fd)
{
	char	**dest;
	char	*tmp;
	int		len_ref;
	int		len_tmp;
	int		line;

	line = 0;
	while ((tmp = get_next_line(fd)) != NULL && tmp[0]) // (1) check si vide
	{
		len_tmp = ft_strlen(tmp);
		if (line == 0)
			len_ref = len_tmp;
		if (len_tmp != len_ref)
			return (MAP_ERROR);
		dest = ft_split(tmp, ' ');
		if (ft_lineisnum(dest) == -1)
			return (MAP_ERROR);
		free(tmp);
		free(dest);
		line++;
	}
	if (tmp == NULL)
		return (0);
	return (-1);
}

/*
Lire ligne par ligne (et stocker chaques lignes)
Verifier si :
- (1) Pas vide
- (2) Chaque lignes a le meme nombre de caractere
- (3) Est compose de "nb  nb  nb  nb..."
- La map entre entierement dans la fenetre
*/