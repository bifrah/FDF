/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:34:49 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/01 16:38:50 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"

typedef struct s_env {
	void	*mlx;
	void	*mlx_win;
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
		my_mlx_pixel_put(env->mlx_win, 5, 5, 0x00FF0000);
	}
	return (0);
}

int	main(void)
{
	t_env	env;

	env.mlx = mlx_init();
	env.mlx_win = mlx_new_window(env.mlx, 1920, 1080, "Hello world!");
	env.img_ptr = mlx_new_image(env.mlx, 1920, 1080);
	env.img_data = mlx_get_data_addr(env.img_ptr, &(env.bits_per_pixel),
			&(env.size_line), &(env.endian));
	mlx_hook(env.mlx_win, 02, (1L << 0), &key_hook, &env);
	mlx_put_image_to_window(env.mlx, env.mlx_win, env.img_ptr, 0, 0);
	mlx_loop(env.mlx);
}
