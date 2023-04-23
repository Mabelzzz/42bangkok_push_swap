/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 01:33:30 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/23 12:45:15 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_push_swap(t_stc *stack);
void	sort_by_len_a(t_stc *stack, t_list **lst, int len);

int	main(int argc, char **argv)
{
	t_stc	stack;

	init_push_swap(&stack);
	if (argc == 1)
		return (0);
	get_val(&stack, argc, argv);
	stack.a = malloc(sizeof(t_stc));
	if (!stack.a)
		return (0);
	get_list(&stack);
	if (check_duplicate(&stack.a) == 1 || stack.cnt == 0)
		error_free(&stack);
	set_index(stack.a);
	if (check_sort(stack.a) == 0)
	{
		free_stack_tmp(&stack);
		free_lst(stack.a);
		return (0);
	}
	sort_by_len_a(&stack, &stack.a, stack.cnt);
	free_stack_tmp(&stack);
	free_lst(stack.a);
	free_lst(stack.b);
	return (0);
}

void	init_push_swap(t_stc *stack)
{
	stack->cnt = 0;
	stack->chunk_size = 0;
	stack->chunk = 0;
	stack->lower = 0;
	stack->upper = 0;
	stack->min = 1;
	stack->max = 0;
	stack->med = 0;
	stack->pb_cnt = 0;
	stack->pa_cnt = 0;
	stack->ra_cnt = 0;
	stack->rb_cnt = 0;
	stack->a = NULL;
	stack->b = NULL;
	stack->tmp = NULL;
}

void	sort_by_len_a(t_stc *stack, t_list **lst, int len)
{
	if (len <= 1)
		return ;
	else if (len == 2)
		sort_2a(stack);
	else if (len == 3)
		sort_3a(stack);
	else if (len <= 15)
		sort_ten(stack, stack->min);
	else if (len == 500)
		quicksort_a(lst, stack, len);
	else
		chunk_sort(stack, len);
}
