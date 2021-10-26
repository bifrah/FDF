/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 14:27:29 by bifrah            #+#    #+#             */
/*   Updated: 2021/06/04 14:27:30 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *large, const char *small, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	tmp;
	char			*c_large;

	c_large = (char *)large;
	if (!(*small))
		return (c_large);
	i = 0;
	tmp = 0;
	while (c_large[i] != '\0' && tmp < size)
	{
		j = 0;
		while (c_large[i + j] == small[j] && tmp++ < size)
		{
			if (small[j + 1] == '\0')
				return (c_large + i);
			j++;
		}
		i++;
		tmp = i;
	}
	return (0);
}
