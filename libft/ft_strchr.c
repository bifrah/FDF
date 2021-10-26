/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 14:27:12 by bifrah            #+#    #+#             */
/*   Updated: 2021/06/04 14:29:50 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*c_s;
	char	c_c;
	int		i;

	c_s = (char *)s;
	c_c = (char)c;
	i = 0;
	if (c_c == '\0')
	{
		while (c_s[i] != c_c)
			i++;
		if (c_s[i] == '\0')
			return (c_s + i);
	}
	while (c_s[i])
	{
		if (c_s[i] == c_c)
			return (c_s + i);
		i++;
	}
	return (0);
}
