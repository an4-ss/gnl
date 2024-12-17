/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arokhsi <arokhsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:43:00 by arokhsi           #+#    #+#             */
/*   Updated: 2024/12/17 16:21:59 by arokhsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_update_data()
{
	
}

static char	*ft_get_line(char *data)
{
	int	i;
	int j;
	char	*buffer;

	if (!data || *data == '\0')
		return (NULL);
	i = 0;
	while (data[i] != '\0' && data[i] != '\n')
		i++;
	buffer = malloc(i + 2);
	if (!buffer)
		return (NULL);
	j = 0;
	while (j < i)
	{
		buffer[j] = data[j];
		j++;
	}
	if (data[i] == '\n')
		buffer[j++] = '\n';
	buffer[j] = '\0';
	return (buffer);
}

static char	*ft_get_data(int fd, char *pre_data)
{
	char	*buffer;
	char	*data;

	if (!pre_data)
		return (ft_empty_string(pre_data));
	if (n_l_check(pre_data))
		return (pre_data);
	buffer = ft_read(fd);
	data = strljoin(pre_data, buffer, ft_strlen(buffer));
	free(buffer);
	return (data);
}

char	*get_next_line(int fd)
{
	static char	*data;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data = ft_get_data(fd, data);
	line = ft_get_line(data);
	data = ft_update_data(data);
	return (line);
}
