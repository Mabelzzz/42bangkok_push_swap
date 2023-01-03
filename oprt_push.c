#include "push_swap.h"

t_list	*push(t_list **stack);
void	pa(t_stc *stack);
void	pb(t_stc *stack);

t_list	*push(t_list **stack)
{
	t_list	*top;

	top = *stack;
	if (!top)
		return (NULL);
	*stack = top->next;
	top->next = NULL;
	return (top);
}

void	pa(t_stc *stack)
{
	t_list	*top;

	top = push(&stack->b);
	ft_lstadd_front(&stack->a, top);
	putstr("pa\n");
}

void	pb(t_stc *stack)
{
	t_list	*top;

	top = push(&stack->a);
	ft_lstadd_front(&stack->b, top);
	putstr("pb\n");
}
