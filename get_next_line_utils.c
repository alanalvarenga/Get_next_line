/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alachris <alachris@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 02:30:05 by alachris          #+#    #+#             */
/*   Updated: 2022/05/06 23:14:55 by alachris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		length;
	char	*cpy;

	i = 0;
	cpy = NULL;
	if (src != NULL)
	{
		length = ft_strlen(src);
		cpy = (char *) malloc(length + 1);
		while (i < length)
		{
			cpy[i] = src[i];
			i++;
		}
		cpy[i] = '\0';
	}
	return (cpy);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	if (c > 127)
		c = c % 256;
	while (*s)
	{
		if (*s == c)
		{
			str = (char *)s;
			return (str);
		}
		s++;
	}
	if (*s == c)
	{
		str = (char *)s;
		return (str);
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1_len;
	unsigned int	i;
	char			*join;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	i = 0;
	join = (char *)malloc((s1_len + ft_strlen(s2) + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	while ((s1[i] != 0) && (s1_len != 0))
	{
		join[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != 0)
	{
		join[s1_len] = s2[i];
		i++;
		s1_len++;
	}	
	join[s1_len] = '\0';
	return (join);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (src == NULL)
		return (0);
	while (src[len] != 0)
		len++;
	if (size > 0)
	{
		while ((i < size -1) && (src[i] != 0))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}	
	return (len);
}
