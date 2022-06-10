/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:09:34 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/10 15:09:35 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exec_sa(t_ps *tab)
{
	ft_stack_swap(&tab->a);
}

void	ft_exec_sb(t_ps *tab)
{
	ft_stack_swap(&tab->b);
}

void	ft_exec_ss(t_ps *tab)
{
	ft_stack_swap(&tab->a);
	ft_stack_swap(&tab->b);
}

void	ft_exec_pa(t_ps *tab)
{
	ft_stack_push_front(&tab->a, ft_stack_pop(&tab->b));
}

void	ft_exec_pb(t_ps *tab)
{
	ft_stack_push_front(&tab->b, ft_stack_pop(&tab->a));
}
