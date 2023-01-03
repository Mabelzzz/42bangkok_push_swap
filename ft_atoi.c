#include "push_swap.h"

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
		printf("Error\n");
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
