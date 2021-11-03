/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:34:49 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/03 20:29:19 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include "../includes/fdf.h"

void	ft_setenv(t_env *env)
{
	env->img_x = 0;
	env->img_y = 0;
	env->mlx = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx, 1920, 1080, "Hello world !");
}

void	my_mlx_pixel_put(t_env *env, int x, int y, int color)
{
	char	*dst;

	dst = env->img_data + (y * env->line_length
			+ x * (env->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw(t_env *env)
{
	int	first_img;

	first_img = 0;
	if (first_img == 1)
		mlx_destroy_image(env->mlx, env->img_ptr);
	env->img_ptr = mlx_new_image(env->mlx, 1920, 1080);
	env->img_data = mlx_get_data_addr(env->img_ptr, &env->bits_per_pixel,
			&env->line_length, &env->endian);
	my_mlx_pixel_put(env, env->img_x, env->img_y, RED);
	mlx_put_image_to_window(env->mlx, env->win_ptr, env->img_ptr, 0, 0);
	if (first_img == 1)
		first_img = 0;
}

int	key_hook(int keycode, t_env *env)
{
	if (keycode == NUMPAD_1)
	{
		env->img_x += 10;
		env->img_y += 10;
	}
	ft_draw(env);
	return (0);
}

int	main(void)
{
	t_env	env;

	ft_setenv(&env);
	ft_draw(&env);
	mlx_hook(env.win_ptr, 2, (1L << 0), &key_hook, &env);
	mlx_loop(env.mlx);
}
