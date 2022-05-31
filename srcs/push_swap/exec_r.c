#include "push_swap.h"

void    ft_exec_ra(t_ps *tab)
{
    ft_stack_rotate(&tab->a);
}

void    ft_exec_rb(t_ps *tab)
{
    ft_stack_rotate(&tab->b);
}

void    ft_exec_rr(t_ps *tab)
{
    ft_stack_rotate(&tab->a);
    ft_stack_rotate(&tab->b);
}