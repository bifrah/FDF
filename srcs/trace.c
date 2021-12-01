/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:17:33 by bifrah            #+#    #+#             */
/*   Updated: 2021/12/01 15:50:25 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	my_mlx_pixel_put(t_env *env, int x, int y, int color)
{
	char	*dst;

	dst = env->img_data + (y * env->line_length
			+ x * (env->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	ft_if(t_env *env, t_point point)
{	
	point.cumul = point.dx / 2;
	point.i = 0;
	while (++point.i <= point.dx)
	{
		point.x += point.xinc;
		point.cumul += point.dy;
		if (point.cumul >= point.dx)
		{
			point.cumul -= point.dx;
			point.y += point.yinc;
		}
		my_mlx_pixel_put(env, point.x + 960, point.y + 540, RED);
	}
}

static void	ft_else(t_env *env, t_point point)
{
	point.cumul = point.dy / 2;
	point.i = 0;
	while (++point.i <= point.dy)
	{
		point.y += point.yinc;
		point.cumul += point.dx;
		if (point.cumul >= point.dy)
		{
			point.cumul -= point.dy;
			point.x += point.xinc;
		}
		my_mlx_pixel_put(env, point.x + 960, point.y + 540, RED);
	}
}

static void	iso(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	ft_trace(t_env *env, t_point point)
{
	iso(&point.xa, &point.ya, point.za);
	iso(&point.xb, &point.yb, point.zb);
	point.x = point.xa;
	point.y = point.ya;
	point.dx = abs(point.xb - point.xa);
	point.dy = abs(point.yb - point.ya);
	point.xinc = -1;
	if ((point.xb - point.xa) > 0)
		point.xinc = 1;
	point.yinc = -1;
	if ((point.yb - point.ya) > 0)
		point.yinc = 1;
	my_mlx_pixel_put(env, point.x + 960, point.y + 540, RED);
	if (point.dx > point.dy)
		ft_if(env, point);
	else
		ft_else(env, point);
}
