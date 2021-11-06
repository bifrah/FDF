/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:34:49 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/06 13:10:19 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_print_error(int errcode)
{
	if (errcode == INPUT_ERROR || errcode == NB_PARAM_ERROR)
		ft_printf("Usage : ./fdf your_map.map");
	return (errcode);
}

int	main(int argc, char **argv)
{
	// t_env	env;
	int	fd;

	if ((fd = ft_check_input(argc, argv)) < 0)
		return (ft_print_error(fd));
	// ft_setenv(&env);
	// ft_draw(&env);
	// mlx_hook(env.win_ptr, 2, (1L << 0), &key_hook, &env);
	// mlx_loop(env.mlx);
}
