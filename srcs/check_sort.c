/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:30:42 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/23 00:00:03 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_sort(t_list *lst);
int	check_sort_min(t_list *tmp, int len);
int	check_sort_max(t_list *tmp, int len);

int	check_sort(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next)
	{
		if (tmp->id > tmp->next->id)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_sort_min(t_list *tmp, int len)
{
	t_list	*lst;

	lst = tmp;
	while (lst->next && len--)
	{
		if (lst->id > lst->next->id)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	check_sort_max(t_list *tmp, int len)
{
	t_list	*lst;

	lst = tmp;
	while (lst->next && len--)
	{
		if (lst->id < lst->next->id)
			return (1);
		lst = lst->next;
	}
	return (0);
}
