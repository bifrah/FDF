/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:34:49 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/22 17:09:38 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_printerr(int errcode)
{
	if (errcode == INPUT_ERROR || errcode == NB_PARAM_ERROR)
		ft_putstr_fd("Usage : ./fdf your_map.map\n", 2);
	if (errcode == MAP_ERROR)
		ft_putstr_fd("Map must have only int, space and \\n. Empty line don't work.\n All the lines must have the same size\n", 2);
	if (errcode == MALLOC_ERROR)
		ft_putstr_fd("Malloc error\n", 2);
	return (errcode);
}

int	main(int argc, char **argv)
{
	t_env	env;
	t_dlist	*list;
	int		fd;

	list = ft_dlistnew();
	fd = ft_check_input(argc, argv);
	if (ft_printerr(fd) < 0 || ft_printerr(ft_check_map(fd)) < 0)
		return (-1);
	ft_setenv(&env);
	ft_stock_input(fd, list);
	//ft_draw(&env);
	mlx_hook(env.win_ptr, 2, (1L << 0), &key_hook, &env);
	mlx_loop(env.mlx);
}
