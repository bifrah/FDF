/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:33:43 by bifrah            #+#    #+#             */
/*   Updated: 2021/12/08 19:34:31 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	moovehook(int keycode, t_env *env)
{
	if (keycode == ZOOM_IN)
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
}

void	rotahook(int keycode, t_env *env)
{
	if (keycode == KEY_X || keycode == KEY_Y || keycode == KEY_Z)
	{
		if (keycode == KEY_X)
			env->chooseangle = 1;
		if (keycode == KEY_Y)
			env->chooseangle = 2;
		if (keycode == KEY_Z)
			env->chooseangle = 3;
		env->angle += 1;
	}
	if (keycode == KEY_H || keycode == KEY_J || keycode == KEY_K)
	{
		if (keycode == KEY_H)
			env->chooseangle = 1;
		if (keycode == KEY_J)
			env->chooseangle = 2;
		if (keycode == KEY_K)
			env->chooseangle = 3;
		env->angle = 0;
	}
}

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
}

int	key_hook(int keycode, t_env *env)
{
	if (keycode == ESC)
	{
		ft_dlistdel(&env->list, DELLIST);
		mlx_destroy_window(env->mlx, env->win_ptr);
		mlx_destroy_display(env->mlx);
		free(env->mlx);
		exit (0);
	}
	else if (keycode == BACKSPACE)
	{
		env->img_x = W_WIDTH / 2;
		env->img_y = W_HEIGHT / 2;
	}
	moovehook(keycode, env);
	key_hook2(keycode, env);
	rotahook(keycode, env);
	ft_draw(env, &(env->list->p_head), env->point);
	return (0);
}
