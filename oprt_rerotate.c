#include "push_swap.h"

void	reverse_rotate(t_list **lst, char st);
// void	rra(t_stc *stack);
// void	rrb(t_stc *stack);
void	rrr(t_stc *stack);

void	reverse_rotate(t_list **lst, char st)
{
	t_list	*cur;
	t_list	*last;

	cur = (*lst);
	last = (*lst);
	last = ft_lstlast(last);
	while (cur != NULL)
	{
		if (cur->next == last)
			cur->next = NULL;
		else
			cur = cur->next;
	}
	ft_lstadd_front(lst, last);
	putstr("rr");
	put_st(st);
}

// void	rra(t_stc *stack)
// {
// 	reverse_rotate(&stack->a);
// 	putstr("rra\n");
// }

// void	rrb(t_stc *stack)
// {
// 	reverse_rotate(&stack->b);
// 	putstr("rrb\n");
// }

void	rrr(t_stc *stack)
{
	reverse_rotate(&stack->a, 'a');
	reverse_rotate(&stack->b, 'b');
}
