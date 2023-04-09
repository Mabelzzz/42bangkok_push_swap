#include "push_swap.h"

int		ft_atoi (char *s);
void	putstr(char *str);
void	put_st(char st);
void	error(void);
void	error_free(t_stc *stack);
void	free_stack_tmp(t_stc *stack);

int	ft_atoi (char *s)
{
	int i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (s[i] == ' ')
		i++;
	// if (s[i] == '0')
	// 	error();
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
	return (sign * result);
}

void	putstr(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

void	put_st(char st)
{
	write(1, &st, 1);
	write(1, "\n", 1);
}

void	error(void)
{
	putstr("Error99\n");
	exit(0);
}

void	error_free(t_stc *stack)
{
	putstr("Error\n");
	free_stack_tmp(stack);
	free_lst(stack->a);
	free_lst(stack->b);
	exit(0);
}

void	free_stack_tmp(t_stc *stack)
{
	int	i;
	int	j;

	i = 0;
	while (stack->tmp[i])
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

int	stack_size(t_list	*stc, t_stc *stack)
{
	t_list	*cur;
	int		i;
	(void) stack;
	i = 0;
	cur = stc;
	while (cur)
	{
		i++;
		cur = cur->next;
	}
	// set_index(stc);
	return (i);
}

void	find_min_max_idex(t_list	*stc, t_stc *stack)
{
	t_list	*cur;

	cur = stc;
	stack->min = cur->id;
	stack->max = cur->id;
	while (cur)
	{
		if (cur->id > stack->max)
			stack->max = cur->id;
		if (cur->id < stack->min)
			stack->min = cur->id;
		cur = cur->next;
	}
}
int	find_stack(t_list	*stc, t_stc *stack, int nbr)
{
	t_list	*cur;
	int		i;
	(void) stack;
	i = 0;
	cur = stc;
	while (cur)
	{
		if (cur->id == nbr)
		{
			if (i < stack_size(stc, stack)/2) //top
				return (0);
			else
				return (1); //down
		}
			return (i);
		i++;
		cur = cur->next;
	}
	// set_index(stc);
	return (i);
}

int stack_top(t_list	*stc)
{
	return (stc->id);
}

int cnt_tmp_size(t_list *stc, int id)
{
	while(stc)
	{
		if (stc->chunk_id)
	}
}
