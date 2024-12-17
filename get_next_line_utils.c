/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arokhsi <arokhsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:16:59 by arokhsi           #+#    #+#             */
/*   Updated: 2024/12/17 16:21:59 by arokhsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd)
{
	char	*tmp;
	char	*buffer;
	int		b_read;

	buffer = ft_empty_string(NULL);
	tmp = malloc[BUFFER_SIZE + 1];
	if (!tmp)
		return (NULL);
	tmp[BUFFER_SIZE] = '\0';
	b_read = read(fd, tmp, BUFFER_SIZE);
	while (b_read > 0)
	{
		buffer = strljoin(buffer, tmp, b_read);
		if (n_l_check(tmp))
			break;
		b_read = read(fd, tmp, BUFFER_SIZE);
	}
	free(tmp)
	if (read_byte <= 0 && !buffer)
		return (NULL);
	return (buffer);
}

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
	char	*buffer;
	int		len;

	len = ft_strlen(s1);
	buffer = malloc(len + size + 1);
	if (!buffer || !s2)
		return (NULL);
	if (!s1)
		s1 = ft_init(NULL);
	ft_strlcat("", s1, len);
	ft_strlcat(buffer, s2, size);
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
char	*ft_strlcat(char *dest, const char *src, size_t size)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && j < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
