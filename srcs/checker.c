/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:14:12 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/23 11:33:26 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_checker(t_stc *stack);
void	read_oprt(t_stc *stack);
int		check_stack(t_stc *stack, char *str, size_t len);
int		check_stack2(char *str, int size_a, int size_b);

int	main(int argc, char **argv)
{
	t_stc	stack;

	init_checker(&stack);
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
	read_oprt(&stack);
	if (!check_sort(stack.a) && !stack_size(stack.b))
		ft_putstr("OK");
	else
		ft_putstr("KO");
	free_stack_tmp(&stack);
	free_lst(stack.a);
	free_lst(stack.b);
	return (0);
}

void	init_checker(t_stc *stack)
{
	stack->cnt = 0;
	stack->a = NULL;
	stack->b = NULL;
	stack->tmp = NULL;
}

void	read_oprt(t_stc *stack)
{
	char	*line;
	size_t	len;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		len = ft_strlen(line);
		if (!find_oprt(line, len))
		{
			free(line);
			error_free(stack);
		}
		if (check_stack(stack, line, len))
			run_oprt(stack, line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
}

int	check_stack(t_stc *stack, char *str, size_t len)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(stack->a);
	size_b = stack_size(stack->b);
	if (len == 3)
		return (check_stack2(str, size_a, size_b));
	else if (len == 4 && str[0] == 'r' && str[1] == 'r')
	{
		if (str[2] == 'a' && size_a >= 2)
			return (1);
		else if (str[2] == 'b' && size_b >= 2)
			return (1);
		else if (str[2] == 'r' && size_a >= 2 && size_b >= 2)
			return (1);
	}
	return (0);
}

int	check_stack2(char *str, int size_a, int size_b)
{
	if (str[0] == 's' || str[0] == 'r')
	{
		if (str[1] == 'a' && size_a >= 2)
			return (1);
		else if (str[1] == 'b' && size_b >= 2)
			return (1);
		else if ((str[1] == 's' || str[1] == 'r') && size_a >= 2 && size_b >= 2)
			return (1);
	}
	else if (str[0] == 'p')
	{
		if (str[1] == 'a' && size_b >= 1)
			return (1);
		else if (str[1] == 'b' && size_a >= 1)
			return (1);
	}
	return (0);
}
