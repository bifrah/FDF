/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:29:03 by bifrah            #+#    #+#             */
/*   Updated: 2021/06/17 17:29:04 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dest, const void *src, int c, unsigned int n)
{
	unsigned int	i;
	char			*c_dest;
	char			*c_src;
	char			c_c;

	c_dest = (char *)dest;
	c_src = (char *)src;
	c_c = (char)c;
	i = 0;
	while (i < n && n > 0)
	{
		if (c_src[i] == c_c)
		{
			c_dest[i] = c_c;
			return (dest + i + 1);
		}
		c_dest[i] = c_src[i];
		i++;
	}
	return (0);
}
