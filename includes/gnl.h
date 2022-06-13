/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:07:26 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/13 03:50:11 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# define FD_SIZE 2

char	*get_next_line(int fd);

char	*ft_strchr_gnl(const char *s, int c, size_t *offset);
char	*ft_strjoin_gnl(char const *s1, char const *s2, \
						size_t len1, size_t len2);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
