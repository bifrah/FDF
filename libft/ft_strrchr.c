/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 14:27:32 by bifrah            #+#    #+#             */
/*   Updated: 2021/06/04 14:29:26 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*c_s;
	char	c_c;
	int		i;

	c_s = (char *)s;
	c_c = (char)c;
	i = 0;
	while (c_s[i])
		i++;
	while (i > -1)
	{
		if (c_s[i] == c_c)
			return (c_s + i);
		i--;
	}
	return (0);
}
