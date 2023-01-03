#include "push_swap.h"

void	rotate(t_list **lst, char st);
// void	ra(t_stc *stack);
// void	rb(t_stc *stack);
void	rr(t_stc *stack);

void	rotate(t_list **lst, char st)
{
	t_list	*cur;

	cur = (*lst);
	*lst = cur->next;
	cur->next = NULL;
	ft_lstadd_back(lst, cur);
	putstr("r");
	put_st(st);
}

// void	ra(t_stc *stack)
// {
// 	rotate(&stack->a);
// 	putstr("ra\n");
// }

// void	rb(t_stc *stack)
// {
// 	rotate(&stack->b);
// 	putstr("rb\n");
// }

void	rr(t_stc *stack)
{
	rotate(&stack->a, 'a');
	rotate(&stack->b, 'b');
}
