/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:22:57 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/23 11:04:27 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_val(t_stc *stack, char st);
void	set_index(t_list *stack);

void	set_val(t_stc *stack, char st)
{
	if (st == 'a')
	{
		stack->x = stack->a->val;
		stack->y = stack->a->next->val;
		stack->z = stack->a->next->next->val;
	}
	if (st == 'b')
	{
		stack->x = stack->b->val;
		stack->y = stack->b->next->val;
		stack->z = stack->b->next->next->val;
	}
}

void	set_index(t_list *stack)
{
	t_list	*cur;
	t_list	*check;
	int		i;
	int		j;

	j = 0;
	cur = stack;
	while (cur)
	{
		i = 1;
		check = stack;
		while (check)
		{
			if (cur->val > check->val)
				i++;
			check = check->next;
		}
		cur->id = i;
		j++;
		cur = cur->next;
	}
}
