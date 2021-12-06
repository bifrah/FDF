/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:33:43 by bifrah            #+#    #+#             */
/*   Updated: 2021/12/06 16:34:51 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, t_env *env, t_dlist *list, t_point point)
{
	if (keycode == ESC)
		exit (0);
	else if (keycode == BACKSPACE)
	{
		env->img_x = W_WIDTH / 2;
		env->img_y = W_HEIGHT / 2;
	}
	else if (keycode == ZOOM_IN)
		env->zoom *= 1.25;
	else if (keycode == ZOOM_OUT)
		env->zoom /= 1.25;
	else if (keycode == RIGHT && env->img_x < W_WIDTH)
		env->img_x += 5;
	else if (keycode == LEFT && env->img_x > 0)
		env->img_x -= 5;
	else if (keycode == DOWN && env->img_y < W_HEIGHT)
		env->img_y += 5;
	else if (keycode == UP && env->img_y > 0)
		env->img_y -= 5;
	ft_draw(env, list, point);
	return (0);
}
