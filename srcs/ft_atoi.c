/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:54:54 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/23 14:46:28 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi(char *s, t_stc *stack)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
	{
		result = (result * 10) + (s[i] - '0');
		i++;
	}
	if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
		error_free(stack);
	return ((int)(sign * result));
}
