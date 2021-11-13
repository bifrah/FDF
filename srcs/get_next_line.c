/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrah <bifrah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 02:28:57 by bifrah            #+#    #+#             */
/*   Updated: 2021/11/13 23:15:17 by bifrah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*first_call(char **line, char *stat)
{
	unsigned int	j;
	int				i;
	char			*tmp;

	i = find_n(*line);
	tmp = ft_strdup(*line);
	line[0][i + 1] = '\0';
	i++;
	j = 0;
	while (tmp[i])
		stat[j++] = tmp[i++];
	stat[j] = '\0';
	free(tmp);
	return (*line);
}

char	*stat_with_n(char *line, char *stat)
{
	unsigned int	i;
	unsigned int	j;
	char			*tmp;

	j = 0;
	line = ft_strjoin_gnl(line, stat);
	i = find_n(line);
	tmp = ft_strdup(stat);
	i++;
	line[i++] = '\0';
	i--;
	while (tmp[i])
		stat[j++] = tmp[i++];
	stat[j] = '\0';
	free(tmp);
	return (line);
}

char	*ft_last_line(char *line, char *stat)
{
	if (line == NULL)
	{
		stat[0] = '\0';
		return (NULL);
	}
	else
	{
		if (find_n(line) == -1)
			return (line);
		else
		{
			stat[0] = '\0';
			line[find_n(line)] = '\0';
			return (line);
		}
	}
	return (line);
}

char	*read_me_please(int fd, char *buff, char *line, char *stat)
{
	int	ret;

	ret = 42;
	while (ret > 0 && find_n(line) == -1)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = '\0';
		line = ft_strjoin_gnl(line, buff);
	}
	if (ret == 0 && ft_strlen(stat) != 0)
		line = ft_last_line(line, stat);
	else if (find_n(line) != -1)
		line = first_call(&line, stat);
	else if (ft_strlen(line) == 0)
	{
		free(line);
		line = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char			buff[BUFFER_SIZE + 1];
	static char		stat[BUFFER_SIZE];
	char			*line;

	if (read(fd, buff, 0) == -1 || BUFFER_SIZE < 1 )
		return (ft_strdup(""));
	line = ft_strdup("");
	if (stat[0])
	{
		if (find_n(stat) != -1)
		{
			line = stat_with_n(line, stat);
			return (line);
		}
		line = ft_strjoin_gnl(line, stat);
		stat[0] = '\0';
	}
	line = read_me_please(fd, buff, line, stat);
	return (line);
}
