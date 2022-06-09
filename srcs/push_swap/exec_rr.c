/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balamosh <balamosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:52:08 by balamosh          #+#    #+#             */
/*   Updated: 2022/06/09 18:52:34 by balamosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exec_rra(t_ps *tab)
{
	ft_stack_rrotate(&tab->a);
}

void	ft_exec_rrb(t_ps *tab)
{
	ft_stack_rrotate(&tab->b);
}

void	ft_exec_rrr(t_ps *tab)
{
	ft_stack_rrotate(&tab->a);
	ft_stack_rrotate(&tab->b);
}
