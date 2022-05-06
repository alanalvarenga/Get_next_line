/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 02:43:44 by alachris          #+#    #+#             */
/*   Updated: 2022/05/06 23:24:04 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_with_n(char **line, char **accumulator, char **tmp, int i)
{
	*line = (char *)malloc(sizeof(char) * (i + 2));
	ft_strlcpy(*line, *accumulator, i + 2);
	ft_strlcpy(*tmp, *accumulator + i + 1, ft_strlen(*accumulator + i) + 1);
}

char	*ft_split_acc(char **accumulator)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	if (*accumulator == NULL)
		return (NULL);
	while ((accumulator[0][i] != '\0') && (accumulator[0][i] != '\n'))
		i++;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(*accumulator) - i + 1));
	if (ft_strchr(*accumulator, '\n'))
		ft_with_n(&line, accumulator, &tmp, i);
	else
	{
		line = (char *)malloc(sizeof(char) * (i + 1));
		ft_strlcpy(line, *accumulator, i + 1);
		free(*accumulator);
		free(tmp);
		return (line);
	}
	free(*accumulator);
	*accumulator = (char *)malloc(sizeof(char) * (ft_strlen(tmp) + 1));
	ft_strlcpy(*accumulator, tmp, ft_strlen(tmp) + 1);
	free(tmp);
	return (line);
}

void	ft_join_acc(char **accumulator, char *buf, int fd)
{
	size_t	result;
	char	*tmp;

	result = read(fd, buf, BUFFER_SIZE);
	while (result)
	{
		buf[result] = '\0';
		if (*accumulator == NULL)
			*accumulator = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(*accumulator, buf);
			if (*accumulator)
				free(*accumulator);
			*accumulator = tmp;
		}
		if (ft_strchr(*accumulator, '\n'))
			break ;
		result = read(fd, buf, BUFFER_SIZE);
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*accumulator;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	ft_join_acc(&accumulator, buf, fd);
	line = ft_split_acc(&accumulator);
	if (buf)
		free(buf);
	return (line);
}
