#include "push_swap.h"

void    ft_exec_sa(t_ps *tab)
{
    ft_stack_swap(&tab->a);
}

void    ft_exec_sb(t_ps *tab)
{
    ft_stack_swap(&tab->b);
}

void    ft_exec_ss(t_ps *tab)
{
    ft_stack_swap(&tab->a);
    ft_stack_swap(&tab->b);
}

void    ft_exec_pa(t_ps *tab)
{
    ft_stack_push_front(&tab->a, ft_stack_pop(&tab->b));
}

#include <stdio.h>

void    ft_exec_pb(t_ps *tab)
{
    ft_stack_push_front(&tab->b, ft_stack_pop(&tab->a));
}
