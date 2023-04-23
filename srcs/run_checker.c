/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:50:13 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/22 22:52:51 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	oprt_ss(t_stc *stack);
void	oprt_rr(t_stc *stack);
void	oprt_rrr(t_stc *stack);
int		find_oprt(char *line, size_t len);
void	run_oprt(t_stc *stack, char *oprt);

void	oprt_ss(t_stc *stack)
{
	swap(&stack->a);
	swap(&stack->b);
}

void	oprt_rr(t_stc *stack)
{
	rotate(&stack->a);
	rotate(&stack->b);
}

void	oprt_rrr(t_stc *stack)
{
	reverse_rotate(&stack->a);
	reverse_rotate(&stack->b);
}

int	find_oprt(char *line, size_t len)
{
	if (len == 3)
	{
		if (ft_strncmp(line, "sa\n", 3)
			|| ft_strncmp(line, "sb\n", 3)
			|| ft_strncmp(line, "ss\n", 3)
			|| ft_strncmp(line, "pa\n", 3)
			|| ft_strncmp(line, "pb\n", 3)
			|| ft_strncmp(line, "ra\n", 3)
			|| ft_strncmp(line, "rb\n", 3)
			|| ft_strncmp(line, "rr\n", 3))
			return (1);
	}
	else if (len == 4)
	{
		if (ft_strncmp(line, "rra\n", 4)
			|| ft_strncmp(line, "rrb\n", 4)
			|| ft_strncmp(line, "rrr\n", 4))
			return (1);
	}
	return (0);
}

void	run_oprt(t_stc *stack, char *oprt)
{
	if (ft_strncmp(oprt, "sa\n", 3))
		swap(&stack->a);
	else if (ft_strncmp(oprt, "sb\n", 3))
		swap(&stack->b);
	else if (ft_strncmp(oprt, "ss\n", 3) && stack->a)
		oprt_ss(stack);
	else if (ft_strncmp(oprt, "pa\n", 3))
		ft_lstadd_front(&stack->a, push(&stack->b));
	else if (ft_strncmp(oprt, "pb\n", 3) == 1)
		ft_lstadd_front(&stack->b, push(&stack->a));
	else if (ft_strncmp(oprt, "ra\n", 3))
		rotate(&stack->a);
	else if (ft_strncmp(oprt, "rb\n", 3) == 1)
		rotate(&stack->b);
	else if (ft_strncmp(oprt, "rr\n", 4) == 1)
		oprt_rr(stack);
	else if (ft_strncmp(oprt, "rra\n", 4))
		reverse_rotate(&stack->a);
	else if (ft_strncmp(oprt, "rrb\n", 4) == 1)
		reverse_rotate(&stack->b);
	else if (ft_strncmp(oprt, "rrr\n", 4) == 1)
		oprt_rrr(stack);
}
