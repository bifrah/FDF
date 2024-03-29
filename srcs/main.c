/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:34:49 by bifrah            #+#    #+#             */
/*   Updated: 2021/12/08 18:37:40 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_printerr(int errcode)
{
	if (errcode == INPUT_ERROR || errcode == NB_PARAM_ERROR)
		ft_putstr_fd("Usage : ./fdf your_map.map\n", 2);
	if (errcode == MAP_ERROR)
		ft_putstr_fd("Map must have only int, space and \\n\
 at the end only.\nAll the lines must have the same size\n", 2);
	if (errcode == MALLOC_ERROR)
		ft_putstr_fd("Malloc error\n", 2);
	if (errcode == NODISPLAY)
		return (errcode);
	return (errcode);
}

int	main(int argc, char **argv)
{
	t_env	env;
	t_dlist	*list;
	t_param	param;
	t_point	point;

	list = ft_dlistnew();
	param.fd = ft_check_input(argc, argv);
	if (ft_printerr(param.fd) < 0 || ft_printerr(ft_check_map(param.fd)) < 0
		|| ft_printerr(ft_stock_input(argv, list)) < 0
		|| ft_printerr(ft_setenv(&env, list, point)) < 0)
	{
		ft_dlistdel(&list, DELLIST);
		return (-1);
	}
	ft_draw(&env, &list->p_head, point);
	mlx_hook(env.win_ptr, 2, (1L << 0), &key_hook, &env);
	mlx_loop(env.mlx);
}
