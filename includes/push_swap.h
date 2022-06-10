/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balamosh <balamosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:29:19 by sotherys          #+#    #+#             */
/*   Updated: 2022/06/10 03:06:13 by balamosh         ###   ########.fr       */
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
	long	ia;
	long	ib;
	long	min_ops;
	long	co_dir;
	void	(*exec[11])(struct s_ps *);
}				t_ps;

typedef enum s_ps_cmd
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}			t_ps_cmd;

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

void    ft_exec_sa(t_ps *tab);
void    ft_exec_sb(t_ps *tab);
void    ft_exec_ss(t_ps *tab);
void    ft_exec_pa(t_ps *tab);
void    ft_exec_pb(t_ps *tab);
void    ft_exec_ra(t_ps *tab);
void    ft_exec_rb(t_ps *tab);
void    ft_exec_rr(t_ps *tab);
void    ft_exec_rra(t_ps *tab);
void    ft_exec_rrb(t_ps *tab);
void    ft_exec_rrr(t_ps *tab);

void	ft_exec(t_ps *tab, t_ps_cmd cmd, long n, t_bool real);

#endif
