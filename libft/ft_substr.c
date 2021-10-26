/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:26:25 by bifrah            #+#    #+#             */
/*   Updated: 2021/06/30 01:28:11 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int	g_malloc(char const *s, unsigned int len)
{
	unsigned int	i;

	i = ft_strlen(s);
	if (i > len)
		return (len);
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	unsigned int	i;
	char			*dest;

	if (s == 0)
		return (0);
	i = 0;
	dest = (char *)malloc(sizeof(char) * (g_malloc(s, len) + 1));
	if (!dest)
		return (0);
	while (i < len && start < ft_strlen(s))
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}
