#include "push_swap.h"

void	sort_four(t_stc *stack, int min)
{
	push_min_b(stack, min);
	sort_three_min(stack, &stack->a, 'a');
	pa(stack);
}

void	sort_five(t_stc *stack, int min)
{
	push_min_b(stack, min);
	push_min_b(stack, min + 1);
	sort_three_min(stack, &stack->a, 'a');
	pa(stack);
	pa(stack);
}

void	sort_ten(t_stc *stack, int min)
{
	int		i;

	i = -1;
	while (++i < stack->cnt - 5)
	{
		push_min_b(stack, min + i);
		// if (i > 1)
		// 	sort_ab(stack);
	}
	min = i;
	sort_five(stack, min);
	i = -1;
	while (++i < stack->cnt - 5)
		pa(stack);
}

void	push_min_b(t_stc *stack, int id)
{
	t_list	*tmp;
	// t_list	*last;

	tmp = stack->a;
	// last = ft_lstlast(tmp);
	if (tmp->id == id)
	{
		pb(stack);
		return ;
	}
	else if (tmp->next->id == id && tmp->id <= stack->cnt / 2)
		swap(&stack->a, 'a');
	else if (tmp->next->id == id && tmp->id > stack->cnt / 2)
		rotate(&stack->a, 'a');
	// else if (last->id == id)
	else
		reverse_rotate(&stack->a, 'a');
	push_min_b(stack, id);
}

void	push_min_b3(t_stc *stack, int id)
{
	t_list	*tmp;
	t_list	*last;

	tmp = stack->a;
	last = ft_lstlast(tmp);
	if (tmp->id == id || tmp->id == id + 1 ||tmp->id == id + 2)
	{
		pb(stack);
		return ;
	}
	else if ((tmp->next->id == id || tmp->next->id == id + 1
			|| tmp->next->id == id + 1) && tmp->id <= stack->cnt / 2)
		swap(&stack->a, 'a');
	else if ((tmp->next->id == id || tmp->next->id == id + 1
			|| tmp->next->id == id + 1) && tmp->id > stack->cnt / 2)
		rotate(&stack->a, 'a');
	else if (last->id == id || last->id == id + 1 || last->id == id + 2)
		reverse_rotate(&stack->a, 'a');
	push_min_b(stack, id);
}
