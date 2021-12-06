/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputandmap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:03:54 by bifrah            #+#    #+#             */
/*   Updated: 2021/12/06 19:23:49 by bifrah           ###   ########.fr       */
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
	t_param	param;

	param.line = 0;
	param.tmp = get_next_line(fd);
	while ((param.tmp != NULL && param.tmp[0]))
	{
		dest = ft_split(param.tmp, ' ');
		param.len_tmp = ptrstrlen(dest);
		if (param.line == 0)
			param.len_ref = param.len_tmp;
		if (param.len_tmp != param.len_ref || ft_lineisnum(dest) == -1)
		{
			ft_free(&param.tmp, &dest);
			return (MAP_ERROR);
		}
		ft_free(&param.tmp, &dest);
		param.line++;
		param.tmp = get_next_line(fd);
	}
	ft_free(&param.tmp, NULL);
	close(fd);
	if (param.tmp == NULL && param.line != 0)
		return (0);
	return (MAP_ERROR);
}
