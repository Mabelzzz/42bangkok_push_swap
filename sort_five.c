#include "push_swap.h"

void	sort_four(t_stc *stack, int min)
{
	// printf("min = %d \n", min);
	while (min <= stack->cnt - 3)
	{
		push_min_b(stack, min);
		min++;
	}
	min = stack->min;
	sort_three(stack);
	while (min <= stack->cnt - 3)
	{
		pa(stack);
		min++;
	}
}

void	sort_five(t_stc *stack, int min)
{
	push_min_b(stack, min);
	push_min_b(stack, min + 1);
	sort_three(stack);
	pa(stack);
	pa(stack);
}

// void	sort_ten(t_stc *stack, int min)
// {
// 	int		i;

// 	i = 0;
// 	printf("min = %d | i = %d\n", min, i);
// 	while (++i <= stack->cnt - 5)
// 		push_min_b3(stack, i);
// 		printf("--min = %d | i = %d\n", min, i);
// 	// min = i;
// 	// sort_five(stack, min);
// 	// i = 0;
// 	// while (++i <= stack->cnt - 5)
// 	// 	pa(stack);
// }

void	push_min_b(t_stc *stack, int id)
{
	t_list	*tmp;
	t_list	*last;
	tmp = stack->a;
	// printf("tmp id = %d\n", tmp->id);
	last = ft_lstlast(tmp);
	if (tmp->id == id)
	{
		pb(stack);
		return ;
	}
	else if (tmp->next->id == id)
		sa(stack);
	else if (last->id == id)
		rra(stack);
	else
	// else if (tmp->id > stack->cnt / 2)
		ra(stack);

	push_min_b(stack, id);
}

// void	push_min_b3(t_stc *stack, int id)
// {
// 	t_list	*tmp;
// 	t_list	*last;

// 	tmp = stack->a;
// 	last = ft_lstlast(tmp);
// 	if (tmp->id == id || tmp->id == id + 1 ||tmp->id == id + 2)
// 	{
// 		pb(stack);
// 		return ;
// 	}
// 	else if ((tmp->next->id == id || tmp->next->id == id + 1
// 			|| tmp->next->id == id + 1) && tmp->id <= stack->cnt / 2)
// 		sa(stack);
// 	else if ((tmp->next->id == id || tmp->next->id == id + 1
// 			|| tmp->next->id == id + 1) && tmp->id > stack->cnt / 2)
// 		ra(stack);
// 	else if (last->id == id || last->id == id + 1 || last->id == id + 2)
// 		rra(stack);
// 	push_min_b3(stack, id);
// }


// void sort_stack(t_list **lst, t_stc *stack)
// {
// 	int sz;
// 	int pivot;
// 	int pushed;

// 	(void) lst;
// 	sz = stack_size(stack->a, stack);
//     if (sz <= 1)
//         return ;
// 	pivot = ((sz / 2) + (sz % 2));
// 	pushed = 0;
//     while (check_sort(stack->a))
//     {
//         if (stack_top(stack->a) < pivot)
//         {
//             pb(stack);
//             pushed++;
//         }
//         else
// 			rotate(&stack->a, 'a');
// 	}

// 	while (pushed--)
// 		pa(stack);
//     // sort_stack(lst, stack);
//     while (stack_size(stack->b, stack))
//         pa(stack);
// }

// Sorts stack a using the quicksort algorithm
// int quicksort(t_list **lst, t_stc *stack, int size)
// {
// 	int	sz_a;
// 	int	sz_b;
//     int pivot;
//     int ra_count = 0;
//     int pb_count = 0;

// 	sz_a = stack_size(stack->a, stack);
// 	set_index(stack->b);
// 	set_index(stack->a);
// 	pivot = ((sz_a / 2) + (sz_a % 2));
//     if (sz_a <= 3)
//     {
//         // sort_small(a, b, size);
// 		// if (size == 2)
// 		// 	sort_two_min(lst, 'a');
// 		// else if (size == 3)
// 		// 	sort_three_min(stack, lst, 'a');
// 		// sort_four(stack, stack->min);
// 		sort_by_len(stack, lst, sz_a);
// 		// printf("\n -----------------------------final---------------------------%d \n", sz_a);
// 		while (stack->a)
// 		{
// 			printf("a = %d ---- id = %d\n", stack->a->val, stack->a->id);
// 			stack->a = stack->a->next;
// 		}
// 		while (stack->b)
// 		{
// 			printf("b = %d ---- id = %d\n", stack->b->val, stack->b->id);
// 			stack->b = stack->b->next;
// 		}
// 		exit(0);
// 		quicksort_back(&stack->b, stack);
//         return (1);
//     }
// 	(void) size;
//     // while (size--)
// 	while(pb_count < pivot)
//     {
// 		sz_b = stack_size(stack->b, stack);
// 		// if (stack->a->id <= pivot)
//         // {
//         //     pb(stack);
//         //     pb_count++;
//         // }
// 		// else if (stack->a->id > stack->a->next->id && stack->a->next->id <= pivot
// 		// 	&& stack->b->id > stack->b->next->id && stack->b)
// 		// 	ss(stack);
// 		// else if (stack->a->id > ft_lstlast(stack->a)->id
// 		// 	&& stack->b->id > ft_lstlast(stack->b)->id && stack->b)
// 		// {
// 		// 	rr(stack);
// 		// 	ra_count++;
// 		// }
// 		// else if (stack->a->id <= ft_lstlast(stack->a)->id && ft_lstlast(stack->a)->id <= pivot
// 		// 	&& stack->b->id <= ft_lstlast(stack->b)->id && stack->b)
// 		// 	rrr(stack);
// 		// else if (stack->a->next->id <= pivot)
// 		// 	swap(&stack->a, 'a');
// 		// else if (ft_lstlast(stack->a)->id <= pivot)
// 		// 	reverse_rotate(&stack->a, 'a');
// 		// else
// 		// {
//         //     rotate(&stack->a, 'a');
//         //     ra_count++;
//         // }
// 		// if (sz_b >= 2)
// 		// {
// 		// 	printf("sz_a = %d  | sz_b = %d | pb_count = %d|\n", sz_a, sz_b, pb_count);
// 		// 	printf("size = %d  |---------> B1 = %d | B2 = %d | Bl = %d |\n", size, stack->b->val, stack->b->next->val, ft_lstlast(stack->b)->val);
// 		// 	printf("pivot = %d |---------> A1 = %d | A2 = %d | Al = %d |\n", pivot, stack->a->id, stack->a->next->id, ft_lstlast(stack->a)->id);
// 		// }
// 		if (stack->a->id <= pivot)
//         {
//             pb(stack);
//             pb_count++;
//         }
// 		else if (stack->a->next->id < pivot)
// 		{
// 			if (sz_b >= 2 && stack->b->next->val > stack->b->val)
// 				ss(stack);
// 			else
// 				sa(stack);
// 			// pb(stack);
//             // pb_count++;
// 		}
// 		// else if (ft_lstlast(stack->a)->id < pivot)
// 		// {
// 			// if (sz_b >= 2 && stack->b->id < ft_lstlast(stack->b)->id)
// 			// 	rrr(stack);
// 		// 	else
// 		// 		rra(stack);
// 		// 	// pb(stack);
//         //     // pb_count++;
// 		// }
// 		// else if (find_stack(stack->a, stack, pivot) == 0 || find_stack(stack->b, stack, sz_b - 1) == 0)
//         // {
//         //     rb(stack);
//         //     // rb_count++;
//         // }
// 		else
//         {
// 			if (sz_b >= 2 && stack->b->id > ft_lstlast(stack->b)->id)
// 				rr(stack);
// 			else
//             	ra(stack);
//             ra_count++;
//         }
// 		// printf("===============================================\n");
//     }
//     while (ra_count-- && sz_b >= 2 && stack->b->id < ft_lstlast(stack->b)->id)
// 	{
// 		// if (sz_b >= 2 && stack->b->id < ft_lstlast(stack->b)->id)
// 			rrr(stack);
// 		// else
//         	// rra(stack);
// 	}
//     quicksort(lst, stack, pb_count);
//     // while (pb_count--)
//     //     pa(stack);
//     // quicksort(lst, stack, stack_size(stack->a, stack));
// 	return (0);
// }

// int quicksort_back(t_list **lst, t_stc *stack)
// {
//         // sort_small(a, b, size);
// 		// if (size == 2)
// 		// 	sort_two_min(lst, 'a');
// 		// else if (size == 3)
// 		// 	sort_three_min(stack, lst, 'a');
// 		// sort_four(stack, stack->min);
// 	int	sz_b;
// 	// int	sz_a;
// 	static int	tmp;
//     // int rb_count = 0;
//     int pa_count = 0;
// 	tmp = 1;
// 	// if (tmp != 0)
// 	// 	sz_b = tmp;
// 	// else
// 	sz_b = stack_size(stack->b, stack);
// 	set_index(stack->b);
// 	set_index(stack->a);
// 	// printf("size = %d | sz = %d |\n", size, sz);
// 	// exit(0);
// 	if (sz_b == 0)
// 	{
// 		// && check_sort(stack->a) == 0
// 		// printf("\n -----------------------------final back--------------------------- \n");
// 		// while (stack->a)
// 		// {
// 		// 	printf("a = %d ---- id = %d\n", stack->a->val, stack->a->id);
// 		// 	stack->a = stack->a->next;
// 		// }
// 		// while (stack->b)
// 		// {
// 		// 	printf("b = %d ---- id = %d\n", stack->b->val, stack->b->id);
// 		// 	stack->b = stack->b->next;
// 		// }
// 		// exit(0);
// 		// free_stack_tmp(stack);
// 		// free_lst(stack->a);
// 		// free_lst(stack->b);
// 		return (0);
// 	}
// 	// pivot = ((sz / 2) + (sz % 2));
//     while (pa_count == 0 && tmp != 0)
//     {
// 		// if (tmp != 0)
// 		// 	sz_b = tmp;
// 		// sz_a = stack_size(stack->a, stack);
//         if (stack->b->id == sz_b || stack->b->id == sz_b - 1)
//         {
//             pa(stack);
//             // pa_count++;
// 			if (stack->a->id == sz_b - 1)
// 			{
// 				tmp = sz_b;
// 				pa_count = 0;
// 				// sz_b = tmp;
// 			}
// 			else
// 			{
// 				tmp = 0;
// 				pa_count++;
// 			}
//         }
// 		else if (stack->b->next->id == sz_b || stack->b->next->id == sz_b - 1)
// 		{
// 			if (stack->a->next->val < stack->a->val)
// 				ss(stack);
// 			else
// 				sb(stack);
// 			// pa(stack);
//             // pa_count++;
// 		}
// 		// else if (ft_lstlast(stack->b)->id == sz || ft_lstlast(stack->b)->id == sz - 1)
// 		// {
// 		// 	rrb(stack);
// 		// 	// pa(stack);
//         //     // pa_count++;
// 		// }
//         else if (find_stack(stack->b, stack, sz_b) == 0 || find_stack(stack->b, stack, sz_b - 1) == 0)
//         {
//             rb(stack);
//             // rb_count++;
//         }
// 		else
// 			rrb(stack);
// 		// if (stack->a->next->val < stack->a->val && stack->b->next->val > stack->b->val && sz_b >= 2)
// 		// 	ss(stack);
// 		// else
// 		if (stack->a->next->val < stack->a->val)
// 			sa(stack);
//     }
//     // while (rb_count--)
//     //     rrb(stack);
//     quicksort_back(lst, stack);
// 	return (0);
// }
