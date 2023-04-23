/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 01:33:32 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/23 10:59:58 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	quicksort_a(t_list **lst, t_stc *stack, int size);
void	set_value_qsa(t_stc *stack, int size);
void	qsa(t_stc *stack);
void	sort_small(t_stc *stack, int size, int i);

void	quicksort_a(t_list **lst, t_stc *stack, int size)
{
	static int	id;

	set_value_qsa(stack, size);
	if (size <= 3)
	{
		sort_small(stack, size, 1);
		id++;
		return ;
	}
	qsa(stack);
	while (stack->ra_cnt-- && size != stack->chunk_size && id)
		rra(stack);
	quicksort_a(lst, stack, size - stack->chunk_size);
	quicksort_b(lst, stack, size / 2 + size % 2);
}

void	set_value_qsa(t_stc *stack, int size)
{
	stack->size_a = stack_size(stack->a);
	stack->size_b = stack_size(stack->b);
	if (check_sort(stack->a) == 0 && stack->size_b == 0)
		return ;
	find_min_max_idex(stack->a, stack, size);
	stack->chunk_size = ((size / 2) + (size % 2));
	stack->med = stack->min + stack->chunk_size - 1;
	stack->pb_cnt = 0;
	stack->ra_cnt = 0;
	stack->rb_cnt = 0;
}

void	qsa(t_stc *stack)
{
	while (stack->pb_cnt != stack->chunk_size)
	{
		if (stack->a->id <= stack->med)
		{
			pb(stack);
			stack->pb_cnt++;
		}
		else
		{
			ra(stack);
			stack->ra_cnt++;
		}
	}
}

void	sort_small(t_stc *stack, int size, int i)
{
	if (i == 1)
	{
		if (size == stack->size_a)
			sort_by_len_a(stack, &stack->a, size);
		else if (size == 2 && stack->a->id > stack->a->next->id)
			sa(stack);
		else if (size == 3)
			sort_3a_top(stack);
	}
	else if (i == 2)
	{
		if (size == 2 && stack->b->id < stack->b->next->id)
			sb(stack);
		else if (size == 3 && stack->size_b == 3)
			sort_3b_bottom(stack);
		else if (size == 3)
			sort_3b_top(stack);
		while (size--)
			pa(stack);
	}
}
