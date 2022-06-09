/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balamosh <balamosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:49:30 by balamosh          #+#    #+#             */
/*   Updated: 2022/06/09 18:50:07 by balamosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exec_ra(t_ps *tab)
{
	ft_stack_rotate(&tab->a);
}

void	ft_exec_rb(t_ps *tab)
{
	ft_stack_rotate(&tab->b);
}

void	ft_exec_rr(t_ps *tab)
{
	ft_stack_rotate(&tab->a);
	ft_stack_rotate(&tab->b);
}
