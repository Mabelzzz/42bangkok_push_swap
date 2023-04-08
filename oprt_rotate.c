#include "push_swap.h"

void	rotate(t_list **lst);
void	ra(t_stc *stack);
void	rb(t_stc *stack);
void	rr(t_stc *stack);

void	rotate(t_list **lst)
{
	t_list	*cur;

	cur = (*lst);
	*lst = cur->next;
	cur->next = NULL;
	ft_lstadd_back(lst, cur);
}

void	ra(t_stc *stack)
{
	rotate(&stack->a);
	putstr("ra\n");
}

void	rb(t_stc *stack)
{
	rotate(&stack->b);
	putstr("rb\n");
}

void	rr(t_stc *stack)
{
	rotate(&stack->a);
	rotate(&stack->b);
	putstr("rr\n");
}
