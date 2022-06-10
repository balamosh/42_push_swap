/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:21:23 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/10 16:32:16 by sotherys         ###   ########.fr       */
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
# ifndef INT_MAX
#  define INT_MAX +2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

void	*ft_memset(void *b, int c, size_t len);
t_bool	ft_malloc(void **ptr, size_t n);
t_bool	ft_calloc(void **ptr, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
long	ft_abs(long x);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_lsign(long x);

#endif
