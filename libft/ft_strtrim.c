/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:26:43 by bifrah            #+#    #+#             */
/*   Updated: 2021/06/17 17:26:52 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>
#include	<stdlib.h>
#include	"libft.h"

static int	comp(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (-1);
		i++;
	}
	return (1);
}

static int	count_b(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && comp(s1[i], set) == -1)
		i++;
	return (i);
}

static int	count_e(char const *s1, char const *set)
{
	int	j;

	j = ft_strlen(s1) - 1;
	while (comp(s1[j], set) == -1 && j >= 0)
		j--;
	return (j + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			*dest;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = count_b(s1, set);
	j = count_e(s1, set);
	k = 0;
	if (i > j)
	{
		dest = malloc(1);
		dest[0] = '\0';
		return (dest);
	}
	dest = (char *)malloc(sizeof(char) * ((j - i) + 1));
	if (!dest)
		return (NULL);
	while (s1[i] && i < j)
		dest[k++] = s1[i++];
	dest[k] = '\0';
	return (dest);
}
