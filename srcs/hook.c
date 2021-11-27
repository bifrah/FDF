/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:33:43 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/27 15:09:59 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, t_env *env, t_dlist *list, t_point point)
{
	if (keycode == ESC)
		exit (0);
	if (keycode == BACKSPACE)
	{
		env->img_x = 960;
		env->img_y = 540;
	}
	if (keycode == RIGHT && env->img_x < 1920)
		env->img_x += 1;
	if (keycode == LEFT && env->img_x > 0)
		env->img_x -= 1;
	if (keycode == DOWN && env->img_y < 1080)
		env->img_y += 1;
	if (keycode == UP && env->img_y > 0)
		env->img_y -= 1;
	ft_draw(env, list, point);
	return (0);
}
