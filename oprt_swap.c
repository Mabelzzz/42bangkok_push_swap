#include "push_swap.h"

void	swap(t_list **lst);
void	sa(t_stc *stack);
void	sb(t_stc *stack);
void	ss(t_stc *stack);

void	swap(t_list **lst)
{
	t_list	*cur;

	cur = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	cur->next = (*lst);
	(*lst) = cur;
	// putstr("s");
	// put_st(st);

}

void	sa(t_stc *stack)
{
	swap(&stack->a);
	putstr("sa\n");
}

void	sb(t_stc *stack)
{
	swap(&stack->b);
	putstr("sb\n");
}

void	ss(t_stc *stack)
{
	swap(&stack->a);
	swap(&stack->b);
	putstr("ss\n");
}
