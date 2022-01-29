/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:16:52 by sotherys          #+#    #+#             */
/*   Updated: 2022/01/29 19:52:57 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\r')
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static long	ft_atol_return(t_bool neg, unsigned long acc, int overflow)
{
	if (overflow)
	{
		if (neg)
			acc = (long)(~(ULONG_MAX >> 1));
		else
			acc = (long)(ULONG_MAX >> 1);
	}
	else if (neg)
		acc = -acc;
	return (acc);
}

static void	ft_atol_init(t_bool neg, \
						unsigned long *cutoff, \
						int *cutlim, \
						unsigned long *acc)
{
	if (neg)
		*cutoff = -(unsigned long)((long)(~(ULONG_MAX >> 1)));
	else
		*cutoff = (ULONG_MAX >> 1);
	*cutlim = *cutoff % 10;
	*cutoff /= 10;
	*acc = 0;
}

long	ft_atol(const char *str)
{
	unsigned long	acc;
	unsigned long	cutoff;
	int				cutlim;
	int				c;
	t_bool			neg;

	neg = FALSE;
	while (ft_isspace(*str))
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = TRUE;
		++str;
	}
	ft_atol_init(neg, &cutoff, &cutlim, &acc);
	while (ft_isdigit(*str))
	{
		c = *str++ - '0';
		if (acc > cutoff || (acc == cutoff && c > cutlim))
			return (ft_atol_return(neg, acc, TRUE));
		else
			acc = acc * 10 + c;
	}
	return (ft_atol_return(neg, acc, FALSE));
}
