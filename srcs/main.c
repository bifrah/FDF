/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:34:49 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/01 17:05:15 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"

typedef struct s_env {
	void	*mlx;
	void	*win_ptr;
	void	*img_ptr;
	void	*img_data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
}				t_env;

void	my_mlx_pixel_put(t_env *img_data, int x, int y, int color)
{
	char	*dst;

	dst = img_data->img_ptr + (y * img_data->size_line
			+ x * (img_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_env *env)
{
	if (keycode == 97)
	{
		mlx_destroy_image(env->mlx, env->img_ptr);
		my_mlx_pixel_put(env->img_data, 5, 5, 0x00FF0000);
		mlx_put_image_to_window(env->mlx, env->win_ptr, env->img_ptr, 0, 0);
	}
	return (0);
}

int	main(void)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win_ptr = mlx_new_window(env.mlx, 1920, 1080, "Hello world !");
	env.img_ptr = mlx_new_image(env.mlx, 1920, 1080);
	env.img_data = mlx_get_data_addr(env.img_ptr, &(env.bits_per_pixel),
			&(env.size_line), &(env.endian));
	mlx_hook(env.win_ptr, 02, (1L << 0), &key_hook, &env);
	mlx_loop(env.mlx);
}
