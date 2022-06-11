#include "push_swap.h"

t_bool	ft_ps_sorted(t_stack *stack)
{
	t_snode	*curr;

	if (stack->size < 2)
		return (TRUE);
	curr = stack->head->next;
	while (curr)
	{
		if (curr->val <= curr->prev->val)
			return (FALSE);
		curr = curr->next;
	}
	return (TRUE);
}