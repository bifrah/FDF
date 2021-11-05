/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:34:49 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/05 12:33:25 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_setenv(t_env *env)
{
	env->img_x = 0;
	env->img_y = 0;
	env->mlx = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx, 1920, 1080, "Hello world !");
}

int	main(void)
{
	t_env	env;

	ft_setenv(&env);
	ft_draw(&env);
	mlx_hook(env.win_ptr, 2, (1L << 0), &key_hook, &env);
	mlx_loop(env.mlx);
}
