/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ten.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 01:32:32 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/23 10:51:23 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_ten(t_stc *stack, int min);
void	push_min_b(t_stc *stack, int id);
void	push_id_b(t_stc *stack, t_list *tmp, int id);
void	push_id_a(t_stc *stack, t_list *tmp, int id);

void	sort_ten(t_stc *stack, int min)
{
	while (min <= stack->cnt - 3)
	{
		push_min_b(stack, min);
		min++;
	}
	min = stack->min;
	sort_3a(stack);
	while (min <= stack->cnt - 3)
	{
		pa(stack);
		min++;
	}
}

void	push_min_b(t_stc *stack, int id)
{
	t_list	*tmp;
	t_list	*last;

	tmp = stack->a;
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
		ra(stack);
	push_min_b(stack, id);
}

void	push_id_b(t_stc *stack, t_list *tmp, int id)
{
	static int	r;

	if (tmp->id == id)
	{
		pb(stack);
		return ;
	}
	else if (tmp->next->id == id)
		sa(stack);
	else
	{
		ra(stack);
		r++;
	}
	while (r--)
		rra(stack);
	push_id_b(stack, tmp, id);
	return ;
}

void	push_id_a(t_stc *stack, t_list *tmp, int id)
{
	static int	r;

	if (tmp->id == id)
	{
		pa(stack);
		return ;
	}
	else if (tmp->next->id == id)
		sb(stack);
	else
	{
		rb(stack);
		r++;
	}
	while (r--)
		rrb(stack);
	push_id_a(stack, tmp, id);
	return ;
}
