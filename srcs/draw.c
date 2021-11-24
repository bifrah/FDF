/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:33:39 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/22 18:44:21 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_env *env, int x, int y, int color)
{
	char	*dst;

	dst = env->img_data + (y * env->line_length
			+ x * (env->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw(t_env *env, t_point point, t_trace trace)
{
	int	first_img;

	first_img = 0;
	if (first_img == 1)
		mlx_destroy_image(env->mlx, env->img_ptr);
	env->img_ptr = mlx_new_image(env->mlx, 1920, 1080);
	env->img_data = mlx_get_data_addr(env->img_ptr, &env->bits_per_pixel,
			&env->line_length, &env->endian);
	//A remplir
	
	ft_trace(env, point, trace);
	
	//Fin remplissage
	mlx_put_image_to_window(env->mlx, env->win_ptr, env->img_ptr, 0, 0);
	if (first_img == 1)
		first_img = 0;
}
