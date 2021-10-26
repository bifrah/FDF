/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:28:04 by bifrah            #+#    #+#             */
/*   Updated: 2021/06/30 00:07:35 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_malloc_j(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_malloc_k(char const *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static char	**winline(char const *s, char c, char **dest, int k)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < ft_malloc_j(s, c) && s[i])
	{
		dest[j] = (char *)malloc(sizeof(char) * (ft_malloc_k(s, c, i) + 1));
		if (!dest[j])
		{
			while (k < j)
				free (dest[k++]);
			free (dest);
			return (NULL);
		}
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			dest[j][k++] = s[i++];
		dest[j++][k] = '\0';
		k = 0;
	}
	dest[j] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		k;

	if (!s)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (ft_malloc_j(s, c) + 1));
	if (!dest)
		return (NULL);
	k = 0;
	winline(s, c, dest, k);
	return (dest);
}
