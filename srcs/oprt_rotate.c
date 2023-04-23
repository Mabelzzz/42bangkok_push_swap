/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oprt_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 01:33:21 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/22 01:33:22 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_list **lst);
void	ra(t_stc *stack);
void	rb(t_stc *stack);
void	rr(t_stc *stack);

void	rotate(t_list **lst)
{
	t_list	*cur;

	cur = (*lst);
	*lst = cur->next;
	cur->next = NULL;
	ft_lstadd_back(lst, cur);
}

void	ra(t_stc *stack)
{
	rotate(&stack->a);
	ft_putstr("ra\n");
}

void	rb(t_stc *stack)
{
	rotate(&stack->b);
	ft_putstr("rb\n");
}

void	rr(t_stc *stack)
{
	rotate(&stack->a);
	rotate(&stack->b);
	ft_putstr("rr\n");
}
