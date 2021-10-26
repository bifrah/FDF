/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:29:48 by bifrah            #+#    #+#             */
/*   Updated: 2021/06/30 01:40:53 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	g_malloc(int n)
{
	int	len;

	len = 0;
	if (n < 10 && n > -1)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*special(int n, char *dest)
{
	if (n == -0 || n == 0)
	{
		dest[0] = '0';
		dest[1] = '\0';
		return (dest);
	}
	if (n == -2147483648)
	{
		dest[0] = '-';
		dest[1] = '2';
		dest[2] = '1';
		dest[3] = '4';
		dest[4] = '7';
		dest[5] = '4';
		dest[6] = '8';
		dest[7] = '3';
		dest[8] = '6';
		dest[9] = '4';
		dest[10] = '8';
		dest[11] = '\0';
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		i;
	int		mem;

	i = g_malloc(n);
	mem = i;
	dest = (char *)malloc(sizeof(char) * (g_malloc(n) + 1));
	if (!dest)
		return (NULL);
	if (n == -2147483648 || n == 0 || n == -0)
		return (special(n, dest));
	if (n < 0)
	{
		n *= -1;
		dest[0] = '-';
	}
	while (n > 0)
	{
		i--;
		dest[i] = (n % 10) + '0';
		n /= 10;
	}
	dest[mem] = '\0';
	return (dest);
}
