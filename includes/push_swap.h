/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:29:19 by sotherys          #+#    #+#             */
/*   Updated: 2022/03/31 00:02:31 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include "hash.h"

typedef struct s_ps
{
	t_stack	a;
	t_stack	b;
}				t_ps;

void	ft_ps_init(t_ps *tab);
void	ft_ps_free(t_ps *tab);
t_bool	ft_ps_parse(t_ps *tab, int ac, char **av);
void	ft_ps_set_index(t_stack *stack);
t_snode	*ft_ps_mfind(t_stack *stack, t_bool (*cmp)(t_snode*, t_snode *));
size_t	ft_ps_mcount(t_stack *stack, \
						t_snode *m, \
						t_bool (*cmp)(t_snode*, t_snode *));
void	ft_ps_mupdate(t_stack *stack, \
						t_snode *m, \
						t_bool (*cmp)(t_snode*, t_snode *));
t_bool	ft_ps_cmp_id(t_snode *lhs, t_snode *rhs);
t_bool	ft_ps_cmp_gt(t_snode *lhs, t_snode *rhs);

size_t	ft_ps_insert_pos(t_stack *stack, int val);

#endif
