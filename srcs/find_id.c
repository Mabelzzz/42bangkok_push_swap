/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:13:04 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/23 11:18:47 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		find_id(t_list *lst, int id);
int		find_less_upper(t_list *lst, int upper);

int	find_id(t_list *lst, int id)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp->next)
	{
		if (tmp->id == id)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i < (stack_size(lst) / 2))
		return (i);
	return (-1);
}

int	find_less_upper(t_list *lst, int upper)
{
	t_list	*tmp;
	int		i;
	int		max;
	int		min;

	i = 0;
	min = stack_size(lst);
	max = 0;
	tmp = lst;
	while (tmp->next)
	{
		if (tmp->id < upper)
		{
			if (i <= min)
				min = i;
			else if (i > max)
				max = i;
		}
		tmp = tmp->next;
		i++;
	}
	i = stack_size(lst);
	if (min <= i - max)
		return (min);
	return (-1);
}
