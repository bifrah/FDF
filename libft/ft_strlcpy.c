/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:27:34 by bifrah            #+#    #+#             */
/*   Updated: 2021/06/30 01:30:22 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int n)
{
	char			*c_src;
	unsigned int	i;
	unsigned int	j;

	if (n == 0)
		return (ft_strlen(src));
	if (src == 0)
		return (0);
	c_src = (char *)src;
	i = 0;
	j = 0;
	while (c_src[j] && j < n - 1)
		dest[i++] = c_src[j++];
	dest[i] = '\0';
	j = ft_strlen(src);
	return (j);
}
