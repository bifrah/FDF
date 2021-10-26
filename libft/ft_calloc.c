/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 14:26:40 by bifrah            #+#    #+#             */
/*   Updated: 2021/06/04 14:26:41 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(unsigned int count, unsigned int size)
{
	char			*dest;
	unsigned int	i;

	dest = (void *)malloc(sizeof(void) * count * size);
	if (!dest)
		return (0);
	i = 0;
	while (i < count * size)
	{
		dest[i] = '\0';
		i++;
	}
	return ((void *)dest);
}
