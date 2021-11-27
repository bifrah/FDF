/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:33:39 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/27 14:50:36 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_draw(t_env *env, t_dlist *list, t_point point)
{
	int		first_img;
	t_dnode	*node;

	node = list->p_head;
	first_img = 0;
	if (first_img == 1)
		mlx_destroy_image(env->mlx, env->img_ptr);
	env->img_ptr = mlx_new_image(env->mlx, 1920, 1080);
	env->img_data = mlx_get_data_addr(env->img_ptr, &env->bits_per_pixel,
			&env->line_length, &env->endian);
	//A remplir
	
	while (point.i < list->length)
	{
		point.xa = point.i;
		point.ya = node->y;
		point.za = node->x[point.i];
		
		point.xb = point.i;
		point.yb = node->p_next->y;
		point.zb = node->x[point.i];

		ft_trace(env, point);

	}
	
	//Fin remplissage
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