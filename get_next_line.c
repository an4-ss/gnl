/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arokhsi <arokhsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:43:00 by arokhsi           #+#    #+#             */
/*   Updated: 2024/12/19 12:08:15 by arokhsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd)
{
	char	*tmp;
	char	*buffer;
	int		b_read;

	buffer = ft_empty_string(NULL);
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	tmp[BUFFER_SIZE] = '\0';
	b_read = read(fd, tmp, BUFFER_SIZE);
	while (b_read > 0)
	{
		buffer = ft_strljoin(buffer, tmp, b_read);
		if (n_l_check(tmp))
			break ;
		b_read = read(fd, tmp, BUFFER_SIZE);
	}
	free(tmp);
	if (b_read <= 0 && !buffer)
		return (NULL);
	return (buffer);
}

static char	*ft_update_data(char *data)
{
	int		i;
	int		data_len;
	char	*new_data;

	if (!data)
		return (NULL);
	data_len = ft_strlen(data);
	i = 0;
	while (data[i] != '\n' && data[i] != '\0')
		i++;
	if (data_len == i)
		return (free(data), NULL);
	new_data = ft_strdup(data + i + 1);
	free(data);
	return (new_data);
}

static char	*ft_get_line(char *data)
{
	int		i;
	char	*buffer;

	if (!data || *data == '\0')
		return (NULL);
	i = 0;
	while (data[i] != '\0' && data[i] != '\n')
		i++;
	buffer = malloc(i + 2);
	if (!buffer)
		return (NULL);
	i = 0;
	while (data[i] != '\0' && data[i] != '\n')
	{
		buffer[i] = data[i];
		i++;
	}
	buffer[i] = data[i];
	buffer[++i] = '\0';
	return (buffer);
}

static char	*ft_get_data(int fd, char *pre_data)
{
	char	*buffer;
	char	*data;

	if (n_l_check(pre_data))
		return (pre_data);
	buffer = ft_read(fd);
	data = ft_strljoin(pre_data, buffer, ft_strlen(buffer));
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
