/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 10:59:02 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/23 10:59:13 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	quicksort_b(t_list **lst, t_stc *stack, int size);
void	set_value_qsb(t_stc *stack, int size);
void	qsb(t_stc *stack);

void	quicksort_b(t_list **lst, t_stc *stack, int size)
{
	static int	id;
	int			sz;

	sz = size;
	id++;
	set_value_qsb(stack, size);
	if (size <= 3)
	{
		sort_small(stack, size, 2);
		id++;
		return ;
	}
	if (stack_size(stack->b) <= 3)
		return ;
	qsb(stack);
	while (stack->rb_cnt-- > 0 && sz != stack->chunk_size && id)
		rrb(stack);
	quicksort_a(lst, stack, stack->chunk_size);
	quicksort_b(lst, stack, sz / 2 + sz % 2);
}

void	set_value_qsb(t_stc *stack, int size)
{
	stack->size_a = stack_size(stack->a);
	stack->size_b = stack_size(stack->b);
	find_min_max_idex(stack->b, stack, size);
	stack->pa_cnt = 0;
	stack->ra_cnt = 0;
	stack->rb_cnt = 0;
	stack->chunk_size = (size / 2);
	stack->med = stack->min + (size / 2) + (size % 2) - 1;
}

void	qsb(t_stc *stack)
{
	while (stack->pa_cnt != stack->chunk_size)
	{
		if (stack->b->id > stack->med)
		{
			pa(stack);
			stack->pa_cnt++;
		}
		else
		{
			rb(stack);
			stack->rb_cnt++;
		}
	}
}
