/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:33:39 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/30 14:14:15 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_draw_trace(t_env *env, t_dlist *list, t_point point)
{
	t_dnode	*node;

	node = list->p_head;
	while (node->y < list->length)
	{
		while (point.i < node->len_x)
		{
			point.xa = point.i;
			point.ya = node->y;
			point.za = node->x[point.i];
			if (point.i + 1 < node->len_x)
			{
				point.xb = point.i + 1;
				point.yb = node->y;
				point.zb = node->x[point.i + 1];
				ft_trace(env, point);
			}
			if (node->p_next->y < list->length)
			{
				point.xb = point.i;
				point.yb = node->p_next->y;
				point.zb = node->p_next->x[point.i];
				ft_trace(env, point);
			}
			point.i++;
		}
		node = node->p_next;
	}
}

void	ft_draw(t_env *env, t_dlist *list, t_point point)
{
	int		first_img;

	first_img = 0;
	if (first_img == 1)
		mlx_destroy_image(env->mlx, env->img_ptr);
	env->img_ptr = mlx_new_image(env->mlx, 1920, 1080);
	env->img_data = mlx_get_data_addr(env->img_ptr, &env->bits_per_pixel,
			&env->line_length, &env->endian);
	ft_draw_trace(env, list, point);
	mlx_put_image_to_window(env->mlx, env->win_ptr, env->img_ptr, 0, 0);
	if (first_img == 1)
		first_img = 0;
}

/*
tracer(t_point a, t_point b);

t_dnode *node;
t_point a;
t_point b;

int x = 0;
int y = 0;

a = {x, y, node.x[x]}
b = {x + 1, y,  node.x[x + 1]}

tracer(a, b);
a = {x, y, node.x[x]}
b = {x, y + 1,  node->p_next.x[x]}
tracer(a, b);
x++;

4 6 0 0
1 2 3 4

*/