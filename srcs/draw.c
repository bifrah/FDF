/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:33:39 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/26 18:01:29 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"





void	ft_draw(t_env *env, t_dlist **list, t_point trace)
{
	int	first_img;

	first_img = 0;
	if (first_img == 1)
		mlx_destroy_image(env->mlx, env->img_ptr);
	env->img_ptr = mlx_new_image(env->mlx, 1920, 1080);
	env->img_data = mlx_get_data_addr(env->img_ptr, &env->bits_per_pixel,
			&env->line_length, &env->endian);
	//A remplir
	



	ft_trace(env, trace);
	
	//Fin remplissage
	mlx_put_image_to_window(env->mlx, env->win_ptr, env->img_ptr, 0, 0);
	if (first_img == 1)
		first_img = 0;
}
