/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:21:23 by sotherys          #+#    #+#             */
/*   Updated: 2022/01/26 10:30:13 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef enum s_bool
{
	FALSE,
	TRUE
}			t_bool;

# ifndef ULONG_MAX
#  define ULONG_MAX ((unsigned long)(~0L))
# endif

t_bool	ft_malloc(void **ptr, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);

#endif
