#include "push_swap.h"

void	get_val(t_stc *stack, int argc, char **argv);
void	get_list(t_stc *stack);

void	get_val(t_stc *stack, int argc, char **argv)
{
	int		i;
	int		j;
	int		nbr;

	i = 0;
	nbr = 0;
	stack->tmp = malloc(sizeof(char **) * (argc));
	while (i < argc - 1)
	{
		stack->tmp[i] = ft_split(argv[i + 1], ' ');
		j = 0;
		while (stack->tmp[i][j])
		{
			check_nbr(stack->tmp[i][j], stack);
			nbr = ft_atoi(stack->tmp[i][j]);
			stack->cnt++;
			j++;
		}
		i++;
	}
	stack->tmp[i] = NULL;
}

void	get_list(t_stc *stack)
{
	int		i;
	int		j;
	t_list	*start;
	t_list	*tmp;

	i = 0;
	stack->a = malloc(sizeof(t_stc));
	stack->a->next = NULL;
	while (stack->tmp[i])
	{
		j = 0;
		while (stack->tmp[i][j])
		{
			if (i == 0 && j == 0)
			{
				stack->a->val = ft_atoi(stack->tmp[i][j]);
				start = stack->a;
			}
			else
			{
				tmp = malloc(sizeof(t_stc));
				tmp->val = ft_atoi(stack->tmp[i][j]);
				tmp->next = NULL;
				stack->a->next = tmp;
				stack->a = stack->a->next;
			}
			j++;
		}
		i++;
	}
	stack->a = start;
	// while (stack->a)
	// {
	// 	printf("stack->a->val -> %d\n", stack->a->val);
	// 	stack->a = stack->a->next;
	// }
}
