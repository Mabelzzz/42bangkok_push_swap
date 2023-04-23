/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 01:32:40 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/23 14:43:00 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(void);
void	error_free(t_stc *stack);
void	check_nbr(char *s, t_stc *stack);
int		check_duplicate(t_list **stack);

void	error(void)
{
	ft_putstr_err("Error\n");
	exit(0);
}

void	error_free(t_stc *stack)
{
	ft_putstr_err("Error\n");
	free_stack_tmp(stack);
	free_lst(stack->a);
	free_lst(stack->b);
	exit(0);
}

void	check_nbr(char *s, t_stc *stack)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	if (s[i] == '-' && s[i + 1] != '\0')
	{
		sign = -1;
		i++;
	}	
	if (s[i] == '+' && s[i + 1] != '\0')
		i++;
	if (s[i] == '0' && sign == -1)
		error_free(stack);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == '\0')
		return ;
	else
		error_free(stack);
}

int	check_duplicate(t_list **stack)
{
	t_list	*cur;
	t_list	*check;

	cur = (*stack);
	while (cur)
	{
		check = cur->next;
		while (check)
		{
			if (cur->val != check->val)
				check = check->next;
			else
				return (1);
		}
		cur = cur->next;
	}
	return (0);
}
