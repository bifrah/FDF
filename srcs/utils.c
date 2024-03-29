/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:05:05 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/26 13:11:22 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_lineisnum(char **dest)
{
	t_param	index;

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
	if (j == 1 && dest[0][0] == '\n')
		return (0);
	return (j);
}

void	ft_freetab(char ***dest)
{
	int	y;

	y = 0;
	while (dest[0][y])
	{
		free(dest[0][y]);
		y++;
	}
	free(*dest);
	*dest = NULL;
}

void	ft_free(char **tmp, char ***dest)
{
	if (*tmp)
	{
		free(*tmp);
		*tmp = NULL;
	}
	if (dest && *dest)
		ft_freetab(dest);
}
