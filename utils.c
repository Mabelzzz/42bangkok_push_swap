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
	if (s[i] == '0')
		error();
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
	putstr("Error\n");
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
