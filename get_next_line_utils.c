/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arokhsi <arokhsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:16:59 by arokhsi           #+#    #+#             */
/*   Updated: 2024/12/18 12:08:56 by arokhsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_empty_string(char *data)
{
	char	*buffer;

	if (data)
		return (data);
	buffer = malloc(1);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	return (buffer);
}

char	*ft_strljoin(char *s1, char *s2, int size)
{
	int		i;
	int		j;
	int		len;
	char	*buffer;

	len = ft_strlen(s1) + size;
	buffer = malloc(len + 1);
	if (!buffer || !s2)
		return (NULL);
	if (!s1)
		s1 = ft_init(NULL);
	i = -1;
	while (s1[++i] != '\0')
		buffer[i] = s1[i];
	j = 0;
	while (s2[j] != '\0' && j < size)
	{
		buffer[i + j] = s2[j];
		j++;
	}
	buffer[i + j] = '\0';
	free(s1);
	return (buffer);
}

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	n_l_check(char	*data)
{
	if (!data)
		return (0);
	while (*data)
	{
		if (*data == '\n')
			return (1);
		data++;
	}
	return (0);
}

char	*ft_strdup(char *str)
{
	char	*buffer;
	int		i;

	if (!str)
		return (NULL);
	buffer = malloc(ft_strlen(str) + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < ft_strlen)
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
