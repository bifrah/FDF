/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:34:49 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/03 17:36:05 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"

typedef struct s_env {
	void	*mlx;
	void	*win_ptr;
	void	*img_data;
	char	*img_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_env;

void	my_mlx_pixel_put(t_env *img_data, int x, int y, int color)
{
	char	*dst;

	dst = img_data->img_ptr + (y * img_data->line_length
			+ x * (img_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_env *env)
{
	if (keycode == 97)
	{
		my_mlx_pixel_put(env, 5, 5, 0x00FF0000);
		mlx_put_image_to_window(env->mlx, env->win_ptr, env->img_data, 0, 0);
	}
	return (0);
}

// void	img_replace(t_env *mlx, t_env win_ptr, t_env img_ptr, t_env img_data)
// {

// }

int	main(void)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx, 1920, 1080, "Hello world !");
	env.img_data = mlx_new_image(env.mlx, 1920, 1080);
	env.img_ptr = mlx_get_data_addr(env.img_data, &env.bits_per_pixel,
			&env.line_length, &env.endian);
	mlx_hook(env.win_ptr, 2, (1L << 0), &key_hook, &env);
	mlx_loop(env.mlx);
}
