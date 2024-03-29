/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:33:39 by bifrah            #+#    #+#             */
/*   Updated: 2021/12/06 19:37:40 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_draw_trace(t_env *env, t_dnode *node, t_point point)
{
	while (++point.or < env->list->length)
	{
		while (++point.ab < node->len_x)
		{
			point.xa = point.ab;
			point.ya = point.or;
			point.za = node->x[point.ab];
			if (point.ab + 1 < node->len_x)
			{
				point.xb = point.ab + 1;
				point.yb = point.or;
				point.zb = node->x[point.ab + 1];
				ft_trace(env, point);
			}
			if (point.or + 1 < env->list->length)
			{
				point.xb = point.ab;
				point.yb = point.or + 1;
				point.zb = node->p_next->x[point.ab];
				ft_trace(env, point);
			}
		}
		node = node->p_next;
		point.ab = -1;
	}
}

void	ft_draw(t_env *env, t_dnode **node, t_point point)
{
	env->img_ptr = mlx_new_image(env->mlx, W_WIDTH, W_HEIGHT);
	env->img_data = mlx_get_data_addr(env->img_ptr, &env->bits_per_pixel,
			&env->line_length, &env->endian);
	ft_setpoint(&point);
	ft_draw_trace(env, *node, point);
	mlx_clear_window(env->mlx, env->win_ptr);
	mlx_put_image_to_window(env->mlx, env->win_ptr, env->img_ptr, -1, -1);
	mlx_destroy_image(env->mlx, env->img_ptr);
}
