/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:48:00 by bifrah            #+#    #+#             */
/*   Updated: 2021/12/08 19:24:14 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_setpoint(t_point *point)
{
	point->ab = -1;
	point->or = -1;
}

int	ft_setenv(t_env *env, t_dlist *list, t_point point)
{
	env->img_x = W_WIDTH / 2;
	env->img_y = W_HEIGHT / 2;
	env->zoom = 20;
	env->mlx = mlx_init();
	if (env->mlx == NULL)
		return (NODISPLAY);
	env->win_ptr = mlx_new_window(env->mlx, W_WIDTH, W_HEIGHT, "Hello world !");
	if (env->win_ptr == NULL)
		return (NODISPLAY);
	env->list = list;
	env->point = point;
	env->point.color = WHITE;
	env->is_iso = 1;
	env->chooseangle = 0;
	env->angle = 0;
	return (0);
}
