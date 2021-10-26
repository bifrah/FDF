/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 14:27:07 by bifrah            #+#    #+#             */
/*   Updated: 2021/06/04 14:27:08 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	unsigned int	i;
	unsigned char	*c_dest;
	unsigned char	*c_src;

	c_dest = (unsigned char *)dest;
	c_src = (unsigned char *)src;
	i = -1;
	if (!dest && !src)
		return (dest);
	if (dest > src)
	{
		while (n--)
			c_dest[n] = c_src[n];
	}
	else
	{
		while (++i < n && n > 0)
			c_dest[i] = c_src[i];
	}
	return (dest);
}
