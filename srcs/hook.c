/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:33:43 by bifrah            #+#    #+#             */
/*   Updated: 2021/12/07 15:59:35 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	key_hook2(int keycode, t_env *env)
{
	if (keycode == KEY_P)
		env->is_iso = (env->is_iso + 1) % 2;
	else if (keycode == KEY_W)
		env->point.color = WHITE;
	else if (keycode == KEY_R)
		env->point.color = RED;
	else if (keycode == KEY_G)
		env->point.color = GREEN;
	else if (keycode == KEY_B)
		env->point.color = BLUE;
	else if (keycode == KEY_M)
		env->point.color = MAGENTA;
	else if (keycode == KEY_C)
		env->point.color = CYAN;
	else if (keycode == KEY_X)
	{
		env->chooseangle = 1;
		env->angle += 20;
	}
	// else if (keycode == KEY_Y)
	// {
	// 	env->chooseangle = 2;
	// 	env->angle += 5;
	// }
	// else if (keycode == KEY_Z)
	// {
	// 	env->chooseangle = 3;
	// 	env->angle += 5;
	// }
}

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
	else if (keycode == LEFT)
		env->img_x -= 5;
	else if (keycode == DOWN && env->img_y < W_HEIGHT - 5)
		env->img_y += 5;
	else if (keycode == UP)
		env->img_y -= 5;
	key_hook2(keycode, env);
	ft_draw(env, &(env->list->p_head), env->point);
	return (0);
}
