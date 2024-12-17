/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arokhsi <arokhsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:43:00 by arokhsi           #+#    #+#             */
/*   Updated: 2024/12/16 20:02:15 by arokhsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd)
{
	char	*tmp;
	char	*buffer;
	int		b_read;

	tmp
}

static char	*ft_update_data()
{
	
}

static char	*ft_get_line()
{
	
}

static char	*ft_get_data(int fd, char *pre_data)
{
	char	*buffer;

	if (!pre_data)
		return (ft_empty_string(pre_data));
	buffer = ft_read(fd);
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
