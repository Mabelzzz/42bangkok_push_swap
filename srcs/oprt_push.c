/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oprt_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 01:33:11 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/22 01:33:12 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*push(t_list **stack);
void	pa(t_stc *stack);
void	pb(t_stc *stack);

t_list	*push(t_list **stack)
{
	t_list	*top;

	top = *stack;
	if (!top)
		return (NULL);
	*stack = top->next;
	top->next = NULL;
	return (top);
}

void	pa(t_stc *stack)
{
	t_list	*top;

	top = push(&stack->b);
	ft_lstadd_front(&stack->a, top);
	ft_putstr("pa\n");
}

void	pb(t_stc *stack)
{
	t_list	*top;

	top = push(&stack->a);
	ft_lstadd_front(&stack->b, top);
	ft_putstr("pb\n");
}
