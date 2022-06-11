/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:07:21 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/11 04:57:01 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*ft_strchr_gnl(const char *s, int c, size_t *offset)
{
	if (!s)
		return (NULL);
	s += *offset;
	while (1)
	{
		if (*s == (char) c)
			return ((char *) s);
		if (*s == '\0')
			break ;
		++s;
		++(*offset);
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2, \
						size_t len1, size_t len2)
{
	char	*new;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	new = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, len1);
	ft_memcpy(new + len1, s2, len2);
	new[len1 + len2] = '\0';
	return (new);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (!s)
		return (NULL);
	new = (char *) malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	ft_memcpy(new, s + start, len);
	new[len] = '\0';
	return (new);
}

static char	*substr_next_line(char **s, int rd, size_t offset)
{
	char	*next_line;
	char	*new_s;

	if (!(*s) || (rd < 0 && !(*s)[0]))
		return (NULL);
	next_line = ft_substr_gnl(*s, 0, offset + 1);
	if (!next_line)
		return (NULL);
	if ((*s)[offset] == '\n')
	{
		new_s = ft_strdup(*s + offset + 1);
		if (!new_s)
			return (NULL);
	}
	else
		new_s = NULL;
	free(*s);
	*s = new_s;
	if (rd > 0 || offset > 0)
		return (next_line);
	free(next_line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*s[FD_SIZE];
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	int			rd;
	size_t		offset;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	rd = 1;
	offset = 0;
	while (!ft_strchr_gnl(s[fd], '\n', &offset))
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd <= 0)
			break ;
		buff[rd] = '\0';
		tmp = ft_strjoin_gnl(s[fd], buff, offset, rd);
		if (!tmp)
			return (NULL);
		free(s[fd]);
		s[fd] = tmp;
	}
	return (substr_next_line(s + fd, rd, offset));
}
