/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:55:20 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/23 11:03:38 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3a(t_stc *stack);
void	sort_3a_top(t_stc *stack);
void	sort_3b_top(t_stc *stack);
void	sort_3b_bottom(t_stc *stack);

void	sort_3a(t_stc *stack)
{
	set_val(stack, 'a');
	if (stack->x < stack->y && stack->x < stack->z && stack->y > stack->z)
		sa(stack);
	if (stack->x > stack->y && stack->x < stack->z && stack->y < stack->z)
		sa(stack);
	if (stack->x > stack->y && stack->x > stack->z && stack->y > stack->z)
		sa(stack);
	set_val(stack, 'a');
	if (stack->x < stack->y && stack->x > stack->z && stack->y > stack->z)
		rra(stack);
	set_val(stack, 'a');
	if (stack->x > stack->y && stack->x > stack->z && stack->y < stack->z)
		ra(stack);
}

void	sort_3a_top(t_stc *stack)
{
	set_val(stack, 'a');
	if (check_sort_min(stack->a, 3) == 0)
		return ;
	if (stack->x > stack->y && stack->x > stack->z)
		sa(stack);
	set_val(stack, 'a');
	if (stack->y > stack->x && stack->y > stack->z)
	{
		ra(stack);
		sa(stack);
		rra(stack);
	}
	set_val(stack, 'a');
	if (stack->z > stack->y && stack->z > stack->x && stack->x > stack->y)
		sa(stack);
}

void	sort_3b_top(t_stc *stack)
{
	set_val(stack, 'b');
	if (stack->x < stack->y && stack->x < stack->z)
		sb(stack);
	set_val(stack, 'b');
	if (stack->y < stack->x && stack->y < stack->z)
	{
		rb(stack);
		sb(stack);
		rrb(stack);
		set_val(stack, 'b');
	}
	if (stack->z < stack->y && stack->z < stack->x && stack->y > stack->x)
		sb(stack);
}

void	sort_3b_bottom(t_stc *stack)
{
	set_val(stack, 'b');
	if (stack->x < stack->z && stack->z < stack->y)
		rb(stack);
	else if (stack->x < stack->y && stack->y < stack->z)
	{	
		rb(stack);
		sb(stack);
	}
	else if (stack->x > stack->y && stack->z > stack->x)
		rrb(stack);
	else if (stack->x > stack->z && stack->z > stack->y)
	{	
		rrb(stack);
		sb(stack);
	}
}
