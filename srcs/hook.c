/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:33:43 by bifrah            #+#    #+#             */
/*   Updated: 2021/12/06 19:14:30 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, t_env *env)
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
	else if (keycode == RIGHT && env->img_x < W_WIDTH - 5)
		env->img_x += 5;
	else if (keycode == LEFT && env->img_x > 5)
		env->img_x -= 5;
	else if (keycode == DOWN && env->img_y < W_HEIGHT - 5)
		env->img_y += 5;
	else if (keycode == UP && env->img_y > 5)
		env->img_y -= 5;
	else if (keycode == KEY_P)
		env->is_iso = (env->is_iso + 1) % 2;
	ft_draw(env, &(env->list->p_head), env->point);
	return (0);
}
