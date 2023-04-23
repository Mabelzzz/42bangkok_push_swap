/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:55:30 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/23 11:03:06 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putstr(char *str);
void	ft_putstr_err(char *str);
void	free_stack_tmp(t_stc *stack);
int		stack_size(t_list	*stc);
void	find_min_max_idex(t_list *stc, t_stc *stack, int len);

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

void	ft_putstr_err(char *str)
{
	while (*str)
	{
		write(STDERR_FILENO, &*str, 1);
		str++;
	}
}

void	free_stack_tmp(t_stc *stack)
{
	int	i;
	int	j;

	i = 0;
	while (stack->tmp && stack->tmp[i])
	{
		j = 0;
		while (stack->tmp[i][j])
		{
			free(stack->tmp[i][j]);
			j++;
		}
		free(stack->tmp[i]);
		i++;
	}
	free(stack->tmp);
}

int	stack_size(t_list *stc)
{
	t_list	*cur;
	int		i;

	i = 0;
	cur = stc;
	while (cur)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}

void	find_min_max_idex(t_list *stc, t_stc *stack, int len)
{
	t_list	*cur;

	cur = stc;
	stack->min = cur->id;
	stack->max = cur->id;
	while (cur && len--)
	{
		if (cur->id > stack->max)
			stack->max = cur->id;
		if (cur->id < stack->min)
			stack->min = cur->id;
		cur = cur->next;
	}
}
