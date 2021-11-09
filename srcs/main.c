/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:34:49 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/09 11:15:01 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_print_error(int errcode)
{
	if (errcode == INPUT_ERROR || errcode == NB_PARAM_ERROR)
		ft_putstr_fd("Usage : ./fdf your_map.map\n", 2);
	return (errcode);
}

int	main(int argc, char **argv)
{
	// t_env	env;
	t_dlist	*list;
	int		fd;

	list = ft_dlistnew();
	fd = ft_check_input(argc, argv);
	if (fd < 0)
		return (ft_print_error(fd));
	ft_check_map(fd, &list);
	// ft_setenv(&env);
	// ft_draw(&env);
	// mlx_hook(env.win_ptr, 2, (1L << 0), &key_hook, &env);
	// mlx_loop(env.mlx);
}
