#include "push_swap.h"

void	sort_hund(t_stc *stack, t_list **lst, char st)
{
	stack->len = stack->cnt;
	quick_sort_pb(stack, lst, st);
	// sort_bylen_min(stack, &stack->a, 'a', stack->cnt - stack->push);
	// sort_bylen_max(stack, &stack->b, 'b', 3);
	// send_back_a(stack);
	// stack->len = stack->push;
	// stack->med = 0;
	// stack->round = 0;
	// quick_sort_pa(stack, &stack->b, 'b');
	// sort_bylen_max(stack, &stack->b, 'b', 3);
	// sort_bylen_min(stack, &stack->a, 'a', 3);
	// send_back_b(stack);
	// printf("len %d med %d push %d\n", stack->cnt - stack->push, stack->med, stack->push);
}

void	send_back_a(t_stc *stack)
{
	if (stack->b->id == stack->a->id - 1 && stack->push > 0)
	{
		pa(stack);
		stack->push--;
	}
	else if (stack->b->next->id == stack->a->id - 1)
		swap(&stack->b, 'b');
	else if (stack->b->next->next->id == stack->a->id - 1)
		rotate(&stack->b, 'b');
	else if (ft_lstlast(stack->b)->id == stack->a->id - 1)
		reverse_rotate(&stack->b, 'b');
	else
		return ;
	send_back_a(stack);
}

void	send_back_b(t_stc *stack)
{
	if (stack->a->id == stack->b->id + 1)
	{
		pb(stack);
		stack->push++;
	}
	else if (stack->a->next->id == stack->b->id + 1)
		swap(&stack->a, 'a');
	else if (stack->a->next->next->id == stack->b->id + 1)
		rotate(&stack->a, 'a');
	// else if (ft_lstlast(stack->a)->id == stack->b->id - 1)
		// reverse_rotate(&stack->a, 'a');
	else
		return ;
	send_back_b(stack);
}

int	quick_sort_pb(t_stc *stack, t_list **lst, char st)
{
	if (stack->push == stack->med)
	{
		stack->round++;
		if(stack->len > 4)
			stack->med = stack->med + (stack->len / 2 + stack->len % 2);
		// else if (stack->len % 2 != 0 && stack->len > 4)
			// stack->med = stack->med + ((stack->len + 1) / 2);
		else
			return (stack->len);
		stack->len = stack->cnt - stack->med;
	}
	if((*lst)->id <= stack->med)
	{
		printf("pb id = %d med = %d-----------\n",(*lst)->id, stack->med);
		pb(stack);
		stack->push++;
	}
	else if((*lst)->next->id  <= stack->med)
		rotate(&stack->a, st);
		// swap(&stack->a, 'a');
	else
		reverse_rotate(&stack->a, st);
	quick_sort_pb(stack, lst, st);
	return (stack->len);
}

int	quick_sort_pa(t_stc *stack, t_list **lst, char st)
{
	if (stack->push == stack->med || stack->med == 0)
	{
		// stack->round++;
		if(stack->len % 2 == 0 && stack->len > 3)
			stack->med = stack->len / 2;
		else if (stack->len % 2 != 0 && stack->len > 3)
			stack->med = (stack->len + 1) / 2;
		else
			return (stack->len);
		stack->len = stack->push - stack->med;
	}
	if((*lst)->id > stack->med)
	{
		printf("id = %d med = %d-----------\n",(*lst)->id, stack->med);
		pa(stack);
		stack->push--;
		if (stack->push <= 3)
			return (stack->len);
	}
	else if((*lst)->next->id  > stack->med)
		rotate(&stack->b, 'b');
		// swap(&stack->a, 'a');
	else
	// if(ft_lstlast(stack->b)->id  >= stack->med)
		reverse_rotate(&stack->b, 'b');
	quick_sort_pa(stack, lst, st);
	return (stack->len);
}
