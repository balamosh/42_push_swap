/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balamosh <balamosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:40:43 by balamosh          #+#    #+#             */
/*   Updated: 2022/06/10 12:40:43 by balamosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_ps_cmp_id(t_snode *lhs, t_snode *rhs)
{
	return (lhs->index - rhs->index == 1);
}

t_bool	ft_ps_cmp_gt(t_snode *lhs, t_snode *rhs)
{
	return (lhs->val > rhs->val);
}
