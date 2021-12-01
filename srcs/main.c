/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:34:49 by bifrah            #+#    #+#             */
/*   Updated: 2021/12/01 16:26:33 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_print_map(t_dlist *list)
{
	t_dnode			*node;
	unsigned int	i;

	node = list->p_head;
	while (node)
	{
		i = 0;
		while (i < node->len_x)
		{
			printf("%d", node->x[i]);
			if (i + 1 < node->len_x)
				printf(" ");
			i++;
		}
		printf("\n");
		node = node->p_next;
	}
}

int	ft_printerr(int errcode)
{
	if (errcode == INPUT_ERROR || errcode == NB_PARAM_ERROR)
		ft_putstr_fd("Usage : ./fdf your_map.map\n", 2);
	if (errcode == MAP_ERROR)
		ft_putstr_fd("Map must have only int, space and \\n at the end only.\nAll the lines must have the same size\n", 2);
	if (errcode == MALLOC_ERROR)
		ft_putstr_fd("Malloc error\n", 2);
	return (errcode);
}

int	main(int argc, char **argv)
{
	t_env	env;
	t_dlist	*list;
	t_param	param;
	t_point	point;

	list = ft_dlistnew();
	param.fd = ft_check_input(argc, argv);
	if (ft_printerr(param.fd) < 0 || ft_printerr(ft_check_map(param.fd)) < 0
		|| ft_printerr(ft_stock_input(argv, list)) < 0)
		return (-1);
	ft_print_map(list);
	ft_setenv(&env);
	ft_draw(&env, list, point);
	mlx_hook(env.win_ptr, 2, (1L << 0), &key_hook, &env);
	mlx_loop(env.mlx);
}
