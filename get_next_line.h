/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arokhsi <arokhsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 10:45:17 by arokhsi           #+#    #+#             */
/*   Updated: 2024/12/18 12:09:05 by arokhsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_empty_string(char *data);
char	*ft_strljoin(char *s1, char *s2, int size);
int		ft_strlen(char *str);
int		n_l_check(char	*data);
char	*ft_strdup(char *str);

#endif