/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:22:16 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/23 11:02:41 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2a(t_stc *stack);
void	sort_2b(t_stc *stack);

void	sort_2a(t_stc *stack)
{
	if (stack->a->val > stack->a->next->val)
		sa(stack);
}

void	sort_2b(t_stc *stack)
{
	if (stack->b->val < stack->b->next->val)
		sb(stack);
}
