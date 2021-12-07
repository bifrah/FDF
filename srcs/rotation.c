/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:07:36 by bifrah            #+#    #+#             */
/*   Updated: 2021/12/07 16:48:41 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_rotation(int *x, int *y, int *z, t_env **env)
{
	if ((*env)->chooseangle == 1)
		ft_xrota(x, y, z, *env);
	if ((*env)->chooseangle == 2)
		ft_yrota(x, y, z, *env);
	if ((*env)->chooseangle == 3)
		ft_zrota(x, y, z, *env);
}

void	ft_xrota(int *x, int *y, int *z, t_env *env)
{
	int	previous_x;
	int	previous_y;
	int	previous_z;

	previous_x = *x;
	previous_y = *y;
	previous_z = *z;
	*x = previous_x;
	*y = previous_y * cos(env->angle) + previous_z * sin(env->angle);
	*z = -(previous_y) * sin(env->angle) + previous_z * cos(env->angle);
}

void	ft_yrota(int *x, int *y, int *z, t_env *env)
{
	int	previous_x;
	int	previous_y;
	int	previous_z;

	previous_x = *x;
	previous_y = *y;
	previous_z = *z;
	*x = previous_x * cos(env->angle) + previous_z * sin(env->angle);
	*y = previous_y;
	*z = previous_x * sin(env->angle) + previous_z * cos(env->angle);
}

void	ft_zrota(int *x, int *y, int *z, t_env *env)
{
	int	previous_x;
	int	previous_y;
	int	previous_z;

	previous_x = *x;
	previous_y = *y;
	previous_z = *z;
	*x = previous_x * cos(env->angle) -(previous_y * sin(env->angle));
	*y = -(previous_x) * sin(env->angle) + previous_y * cos(env->angle);
	*z = previous_z;
}
