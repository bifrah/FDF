/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:17:33 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/22 18:20:44 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_trace(t_env env, t_point point, t_trace trace)
{
	trace.x = point.xa;
	trace.y = point.ya;
	trace.dx = point.xb - point.xa;
	trace.dy = point.yb - point.ya;
	if (trace.dx > 0)
		trace.xinc = 1;
	else
		trace.xinc = -1;
	if (trace.dy > 0)
		trace.yinc = 1;
	else
		trace.yinc = -1;
	trace.dx = abs(trace.dx);
	trace.dy = abs(trace.dy);
	my_mlx_pixel_put(&env, trace.x, trace.y, RED);
	if (trace.dx > trace.dy)
	{
		trace.cumul = trace.dx / 2;
		trace.i = 0;
		while (++trace.i <= trace.dx)
		{
			trace.x += trace.xinc;
			trace.cumul += trace.dy;
			if (trace.cumul >= trace.dx)
			{
				trace.cumul -= trace.dx;
				trace.y += trace.yinc;
			}
			my_mlx_pixel_put(&env, trace.x, trace.y, RED);
		}
	}
	else
	{
		trace.cumul = trace.dy / 2;
		trace.i = 0;
		while (++trace.i <= trace.dy)
		{
			trace.y += trace.yinc;
			trace.cumul += trace.dx;
			if (trace.cumul >= trace.dy)
			{
				trace.cumul -= trace.dy;
				trace.x += trace.xinc;
			}
			my_mlx_pixel_put(&env, trace.x, trace.y, RED);
		}
	}
}
