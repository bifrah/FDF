/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:30:09 by bifrah            #+#    #+#             */
/*   Updated: 2021/06/17 17:30:10 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\v' || c == '\t' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	score;

	i = 0;
	result = 0;
	score = 1;
	while (ft_space(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			score = -1;
		i++;
	}
	while (ft_isdigit (str[i]) == 1)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (score * result);
}
