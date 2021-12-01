/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:48:00 by bifrah            #+#    #+#             */
/*   Updated: 2021/12/01 16:36:49 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_setenv(t_env *env)
{
	env->img_x = 0;
	env->img_y = 0;
	env->havetodestroy = 0;
	env->mlx = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx, W_WIDTH, W_HEIGHT, "Hello world !");
}
