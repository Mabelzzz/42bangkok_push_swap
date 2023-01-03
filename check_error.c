#include "push_swap.h"

void	check_nbr(char *s, t_stc *stack);
int		check_duplicate(t_list **stack);

void	check_nbr(char *s, t_stc *stack)
{
	int i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == '\0')
		return ;
	error_free(stack);
}

int	check_duplicate(t_list **stack)
{
	t_list	*cur;
	t_list	*check;

	cur = (*stack);
	while(cur)
	{
		check = cur->next;
		while (check)
		{
			if (cur->val != check->val)
			{
				// printf("cur->val -> \n", cur->val);
				check = check->next;
			}
			else
				return (1);
		}
		cur = cur->next;
	}
	return (0);
}
