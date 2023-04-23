/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 01:33:08 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/23 14:37:48 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_val(t_stc *stack, int argc, char **argv);
void	cnt_stack(t_stc *stack, char **argv, int i);
void	get_list(t_stc *stack);
t_list	*get_tmp(t_list *tmp, t_stc *stack, int i, int j);

void	get_val(t_stc *stack, int argc, char **argv)
{
	int		i;

	i = 0;
	if (argv[1][0] == 0)
		error();
	stack->tmp = malloc(sizeof(char **) * (argc));
	if (!stack->tmp)
		return ;
	stack->tmp[argc - 1] = NULL;
	while (i < argc - 1)
	{
		cnt_stack(stack, argv, i);
		i++;
		if (stack->cnt == 0)
			error_free(stack);
	}
}

void	cnt_stack(t_stc *stack, char **argv, int i)
{
	int		j;

	stack->tmp[i] = ft_split(stack, argv[i + 1], ' ');
	if (!stack->tmp[i])
		error_free(stack);
	j = 0;
	while (stack->tmp[i][j])
	{
		check_nbr(stack->tmp[i][j], stack);
		stack->cnt++;
		j++;
	}
}

void	get_list(t_stc *stack)
{
	int		i;
	int		j;
	t_list	*start;
	t_list	*tmp;

	i = 0;
	stack->a->next = NULL;
	while (stack->tmp[i])
	{
		j = 0;
		while (stack->tmp[i][j])
		{
			if (i == 0 && j == 0)
			{
				stack->a->val = ft_atoi(stack->tmp[i][j], stack);
				start = stack->a;
			}
			else
				tmp = get_tmp(tmp, stack, i, j);
			j++;
		}
		i++;
	}
	stack->a = start;
}

t_list	*get_tmp(t_list *tmp, t_stc *stack, int i, int j)
{
	tmp = malloc(sizeof(t_stc));
	if (!tmp)
		return (NULL);
	tmp->val = ft_atoi(stack->tmp[i][j], stack);
	tmp->next = NULL;
	stack->a->next = tmp;
	stack->a = stack->a->next;
	return (tmp);
}
