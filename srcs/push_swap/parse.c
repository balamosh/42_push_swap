/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:10:27 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/24 11:20:58 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	ft_isnumber(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (FALSE);
		++str;
	}
	return (TRUE);
}

t_bool	ft_ps_parse(t_ps *tab, int ac, char **av)
{
	t_bool	flag;
	t_hash	set;
	int		i;
	long	n;

	if (!ft_hash_init(&set))
		return (FALSE);
	i = 0;
	flag = TRUE;
	while (i < ac && flag)
	{
		n = ft_atol(av[i]);
		flag = (n <= INT_MAX && n >= INT_MIN && ft_isnumber(av[i]) && \
				!ft_hash_contains(&set, n) && \
				ft_hash_insert(&set, n) && \
				ft_stack_push_back(&tab->a, ft_stack_new(n)));
		++i;
	}
	ft_hash_free(&set);
	if (!flag)
		ft_stack_free(&tab->a);
	return (flag);
}
