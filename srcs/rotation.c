/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:07:36 by bifrah            #+#    #+#             */
/*   Updated: 2021/12/07 16:01:36 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_rotation(int *x, int *y, int *z, t_env **env)
{
	if ((*env)->chooseangle == 1)
		ft_xrota(x, y, z, *env);
	// if ((*env)->chooseangle == 2)
	// 	ft_yrota(&x, &y, &z, &env);
	// if ((*env)->chooseangle == 3)
	// 	ft_zrota(&x, &y, &z, &env);
}

void    ft_xrota(int *x, int *y, int *z, t_env *env)
{
    int xtmp;
    int ytmp;
    int ztmp;

    xtmp = *x;
    ytmp = *y * cos(env->angle) + *z * sin(env->angle);
    ztmp = -(*y) * sin(env->angle) + *z * cos(env->angle);

    *x = xtmp;
    *y = ytmp;
    *z = ztmp;
}
