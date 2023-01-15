#include "push_swap.h"

// void	sort_hundred(t_stc *stack)
void	sort_hundred(t_stc *stack, t_list **lst, char st)
{
	(void) lst;
	(void) st;
	stack->min = stack->cnt - stack->range;
	// printf("-----------------------------------------------------\n");
	// printf("\nbefore push = %d cnt = %d  range = %d\n",stack->push, stack->cnt, stack->range);
	// push_b(stack, 1);
	// printf("push = %d cnt = %d  range = %d\n",stack->push, stack->cnt, stack->range);
	// printf("-----------------------------------------------------\n");

	// printf("\nbefore push = %d cnt = %d  range = %d\n",stack->push, stack->cnt, stack->range);
	// push_b(stack, 1);
	// printf("push = %d cnt = %d  range = %d\n",stack->push, stack->cnt, stack->range);
	// printf("-----------------------------------------------------\n");


	// printf("\nbefore push = %d cnt = %d  range = %d\n",stack->push, stack->cnt, stack->range);
	// push_b(stack, 1);
	// printf("push = %d cnt = %d  range = %d\n",stack->push, stack->cnt, stack->range);
	// printf("-----------------------------------------------------\n");

	// printf("\nbefore push = %d cnt = %d  range = %d\n",stack->push, stack->cnt, stack->range);
	// push_b(stack, 1);
	printf("push = %d cnt = %d  range = %d chunk = %d --%d\n",stack->push, stack->cnt, stack->range, stack->chunk, stack->cnt/stack->chunk);
	find_max(stack);
	// sort_ab(stack, 1);
	// sort_ab(stack, 1);
	// sort_ab(stack, 1);
	// sort_ab(stack, 1);
	// sort_ab(stack);
	// if (stack->range <= 200)
	// 	sort_bylen(stack, stack->range);
}

void	push_b(t_stc *stack, int ck)
{
	t_list	*tmp;
	// t_list	*last;

	tmp = stack->a;
	// last = ft_lstlast(tmp);
	if (tmp->id <= stack->range * ck)
	{
		stack->push++;
		printf("======= push = %d \n", stack->push);
		pb(stack);
		return ;
	}
	else if (tmp->next->id <= stack->range * ck && tmp->id <= stack->range * ck / 2)
		swap(&stack->a, 'a');
	else if (tmp->next->id <= stack->range * ck && tmp->id > stack->range * ck / 2)
		rotate(&stack->a, 'a');
	// else if (last->id == id)
	else
		reverse_rotate(&stack->a, 'a');
	push_b(stack, ck);
}

void	find_max(t_stc *stack)
{
	// t_list	*last;
	int		r;
	int		c;

	c = 1;
	r = stack->range;
	while (stack->push < stack->cnt - stack->range)
	// while (stack->push <  2)
	{
		// if (i > 1)
		// {
		// 	last = ft_lstlast(stack->b);
		// 	if (b->id < b->next->id)
		// 		swap(&stack->b, 'b');
		// 	if (b->id < r / 2)
		// 		rotate(&stack->b, 'b');
		// 	else if (last->id >= r / 2)
		// 		reverse_rotate(&stack->b, 'b');
		// }
		// last = ft_lstlast(stack->a);


		push_b(stack, c);
		printf("push = %d c =%d\n", stack->push,c);
		if (stack->push == stack->range * c && c < stack->chunk - 1)
		// if (stack->push == 2 && c < stack->chunk - 1)
		{
			printf("c = %d\n", c);
			c++;
		}
		// if (a->id < r)
		// {
		// 	pb(stack);
		// 	i++;
		// }
		// else
		// 	sort_a(stack, a, ft_lstlast(a), c);
		// printf(" s = %d\n", stack->range * c / 2);
		// i++;
		// else if (a->next->id < r && a->id <= (r * stack->chunk / 2))
		// 	swap(&stack->a, 'a');
		// else if (a->next->id < r && a->id > (r * stack->chunk / 2))
		// 	rotate(&stack->a, 'a');
		// // else if (last->id < r)
		// // 	reverse_rotate(&stack->a, 'a');
		// else
		// 	reverse_rotate(&stack->a, 'a');
		// exit(0);
		// printf ("i = %d r = %d cnt = %d range = %d chunk = %d\n", i, r, stack->cnt, stack->range, stack->chunk);
	}
	// if (i == stack->cnt - stack->range)
	// 	return ;
	// find_max(stack);
}
