/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:48:00 by bifrah            #+#    #+#             */
/*   Updated: 2021/12/06 19:36:49 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_setpoint(t_point *point)
{
	point->ab = -1;
	point->or = -1;
}

void	ft_setenv(t_env *env, t_dlist *list, t_point point)
{
	env->img_x = W_WIDTH / 2;
	env->img_y = W_HEIGHT / 2;
	env->zoom = 20;
	env->mlx = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx, W_WIDTH, W_HEIGHT, "Hello world !");
	env->list = list;
	env->point = point;
	env->is_iso = 1;
}
