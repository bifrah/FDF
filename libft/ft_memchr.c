/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 14:26:59 by bifrah            #+#    #+#             */
/*   Updated: 2021/06/04 14:27:00 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned int	i;
	unsigned char	*c_s;
	unsigned char	c_c;

	c_s = (unsigned char *)s;
	c_c = (unsigned char)c;
	i = -1;
	while (++i < n)
	{
		if (c_s[i] == c_c)
			return (&c_s[i]);
	}
	return (0);
}
