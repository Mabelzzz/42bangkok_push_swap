/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 01:32:19 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/23 11:18:34 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	chunk_sort(t_stc *stack, int size);
void	send_to_b(t_stc *stack);
void	sort_b(t_stc *stack, int f);
void	send_to_a(t_stc *stack, int id);

void	chunk_sort(t_stc *stack, int size)
{
	int	ck;
	int	i;
	int	n;

	i = 0;
	n = 0;
	ck = (size / 100) + 3;
	stack->upper = 1;
	stack->chunk_size = (size / ck) + (size % ck);
	while (i++ < ck)
	{
		if (i > 1)
			stack->chunk_size = (size / ck);
		stack->lower = stack->upper;
		stack->upper = stack->lower + stack->chunk_size;
		if (i == ck)
			stack->upper -= 3;
		stack->med = stack->lower + (stack->chunk_size / 2);
		send_to_b(stack);
	}
	i = stack_size(stack->a);
	sort_by_len_a(stack, &stack->a, i);
	n = size - i + 1;
	while (--n > 0)
		send_to_a(stack, n);
}

void	sort_b(t_stc *stack, int f)
{
	if (stack->a->id >= stack->upper && stack->b->id < stack->med)
		rr(stack);
	else if ((ft_lstlast(stack->a)->id < stack->upper
			|| f == -1) && ft_lstlast(stack->b)->id >= stack->med)
		rrr(stack);
	else if (stack->b->id < stack->med)
		rb(stack);
}

void	send_to_b(t_stc *stack)
{
	int	f;

	while (stack->pb_cnt < stack->upper - 1)
	{
		f = find_less_upper(stack->a, stack->upper);
		if (stack_size(stack->a) <= 3)
			return ;
		if (stack->a->id < stack->upper)
		{
			pb(stack);
			stack->pb_cnt++;
			if (stack_size(stack->b) >= 2)
				sort_b(stack, f);
		}
		else if (ft_lstlast(stack->a)->id < stack->upper || f == -1)
			rra(stack);
		else
			ra(stack);
	}
}

void	send_to_a(t_stc *stack, int id)
{
	int	finder;

	finder = find_id(stack->b, id);
	while (stack_size(stack->b) != 0)
	{
		if (stack->b->id == stack->a->id - 1)
		{
			pa(stack);
			stack->pa_cnt++;
			return ;
		}
		else if (finder != -1)
			rb(stack);
		else
			rrb(stack);
	}
	return ;
}
