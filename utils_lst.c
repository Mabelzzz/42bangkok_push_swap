#include "push_swap.h"

void	free_lst(t_list *lst)
{
	t_list	*cur;

	while (lst != NULL)
	{
		cur = lst->next;
		free(lst);
		lst = cur;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		if (lst -> next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_list	*ft_lstnew(int val)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->val = val;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (ft_lstlast(*lst) == NULL)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst && !new)
		return ;
	// if (!*lst)

	new->next = *lst;
	*lst = new;
}
// t_stack	*tmp;

// 	if (*stack == NULL)
// 		*stack = new;
// 	else
// 	{
// 		tmp = *stack;
// 		*stack = new;
// 		new->next = tmp;
// 	}
