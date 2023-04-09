#include "push_swap.h"

int quicksort(t_list **lst, t_stc *stack, int size)
{
	static int	id;

	id = qs_pb(lst, stack, size);
	while (id--)
	{
		// stack->tmp_sz = cnt_tmp_size
		printf("id-->%d\n", id);
	}
	// while (stack->a)
	// {
	// 	printf("a = %d ---- id = %d\n", stack->a->val, stack->a->id);
	// 	stack->a = stack->a->next;
	// }
	// while (stack->b)
	// {
	// 	printf("b = %d ---- id = %d| ck_id = %d\n", stack->b->val, stack->b->id, stack->b->chunk_id);
	// 	stack->b = stack->b->next;
	// }
	return (0);
}


int qs_pb(t_list **lst, t_stc *stack, int size)
{
	static int	id;
    // int ra_cnt = 0;
    // int pb_cnt = 0;
	// id = 1;
	stack->size_a = stack_size(stack->a, stack);
	stack->size_b = stack_size(stack->b, stack);
	find_min_max_idex(stack->a, stack);

	stack->chunk_size = ((size / 2) + (size % 2));
	stack->lower = stack->min;
	stack->upper = stack->min + stack->chunk_size - 1;
	stack->pb_cnt = 0;
	id++;
	// printf("min = %d| max = %d| low = %d | up = %d|\n", stack->min, stack->max, stack->lower, stack->upper);
	printf("Before------> id = %d | size = %d| ck_id = %d|\n", id, size, stack->chunk_size);
	// printf("ck_id = %d | size = %d | pb = %d|\n", stack->chunk_size, size, stack->pb_cnt);
	t_list *tmp;
    if (size <= 3)
    {
		sort_by_len(stack, lst, size);
		tmp = stack->a;
		printf("\n -----------------------------final---------------------------\n");
		while (tmp)
		{
			printf("a = %d ---- id = %d\n", tmp->val, tmp->id);
			tmp = tmp->next;
		}
		tmp = stack->b;
		while (tmp)
		{
			printf("b = %d ---- id = %d| ck_id = %d\n", tmp->val, tmp->id, tmp->chunk_id);
			tmp = tmp->next;
		}
        return (id);
		// exit(0);
		// quicksort_back(&stack->b, stack);
    }
	while(stack->pb_cnt != stack->chunk_size && size--)
    {

		// printf("id = %d | up = %d|\n", stack->a->id, stack->upper);
		if (stack->a->id <= stack->upper)
        {
			printf("id = %d | up = %d|\n", id, stack->upper);
			stack->a->chunk_id = id;
            pb(stack);
			// stack->b = stack->b->next;
            stack->pb_cnt++;

        }
		else if (stack->a->next->id < stack->a->id && stack->size_b >= 2 && stack->b->next->val > stack->b->val)
			ss(stack);
		else
        {
			// if (stack->size_b >= 2 && stack->b->id > ft_lstlast(stack->b)->id)
			// 	rr(stack);
			// else
            	ra(stack);
            stack->ra_cnt++;
        }
    }
	while (stack->ra_cnt-- && stack->size_b >= 2 && stack->b->id < ft_lstlast(stack->b)->id)
	{
		// if (sz_b >= 2 && stack->b->id < ft_lstlast(stack->b)->id)
			rrr(stack);
	}
	printf("After------> id = %d | size = %d|\n", id, stack->size_a - stack->chunk_size);
	qs_pb(lst, stack, stack->size_a - stack->chunk_size);
	id--;
	// qs_pa(lst, stack, id);
	// printf("finishbb-- a = %d | b = %d \n", stack_size(stack->a, stack), stack_size(stack->b, stack));
	printf("\n final--------finishbb-- a = %d | b = %d | id = %d\n", stack_size(stack->a, stack), stack_size(stack->b, stack), id);
	tmp = stack->a;
	while (tmp)
	{
		printf("a = %d ---- id = %d\n", tmp->val, tmp->id);
		tmp = tmp->next;
	}
	tmp = stack->b;
	while (tmp)
	{
		printf("b = %d ---- id = %d| ck_id = %d\n", tmp->val, tmp->id, tmp->chunk_id);
		tmp = tmp->next;
	}
	return (0);
}

int qs_pa(t_list **lst, t_stc *stack, int id)
{
	static int	id;
    // int ra_cnt = 0;
    // int pb_cnt = 0;
	// id = 1;
	stack->size_a = stack_size(stack->a, stack);
	stack->size_b = stack_size(stack->b, stack);
	find_min_max_idex(stack->a, stack);

	stack->chunk_size = cnt_tmp_size(stack->b, id)
	stack->lower = stack->min;
	stack->upper = stack->max - stack->chunk_size + 1;
	stack->pa_cnt = 0;
	// id++;
	// printf("min = %d| max = %d| low = %d | up = %d|\n", stack->min, stack->max, stack->lower, stack->upper);
	printf("Before------> id = %d | size = %d| ck_id = %d|\n", id, size, stack->chunk_size);
	// printf("ck_id = %d | size = %d | pb = %d|\n", stack->chunk_size, size, stack->pb_cnt);
    if (size <= 3)
    {
		sort_by_len(stack, lst, size);
		// printf("\n -----------------------------final---------------------------%d \n", sz_a);
		while (stack->a)
		{
			printf("a = %d ---- id = %d\n", stack->a->val, stack->a->id);
			stack->a = stack->a->next;
		}
		while (stack->b)
		{
			printf("b = %d ---- id = %d| ck_id = %d\n", stack->b->val, stack->b->id, stack->b->chunk_id);
			stack->b = stack->b->next;
		}
        return (id);
		exit(0);
		// quicksort_back(&stack->b, stack);
    }
	while(stack->pa_cnt != stack->chunk_size && size--)
    {

		// printf("id = %d | up = %d|\n", stack->a->id, stack->upper);
		if (stack->b->id >= stack->upper)
        {
			printf("id = %d | up = %d|\n", id, stack->upper);
			stack->a->chunk_id = id;
            pa(stack);
			// stack->b = stack->b->next;
            stack->pa_cnt++;

        }
		else if (stack->b->next->id < stack->b->id && stack->size_a >= 2 && stack->a->next->val > stack->a->val)
			ss(stack);
		else
        {
			if (stack->size_a >= 2 && stack->a->id > ft_lstlast(stack->a)->id)
				rr(stack);
			else
            	rb(stack);
            stack->rb_cnt++;
        }
    }
	while (stack->rb_cnt-- && stack->size_a >= 2 && stack->a->id < ft_lstlast(stack->a)->id)
	{
		// if (sz_b >= 2 && stack->b->id < ft_lstlast(stack->b)->id)
			rrr(stack);
	}
	// printf("After------> id = %d | size = %d|\n", id, stack->size_a - stack->chunk_size);
	qs_pb(lst, stack, stack->size_a - stack->chunk_size);
	// qs_pa(lst, stack, stack->size_b - stack->chunk_size);
	// while (stack->a)
	// {
	// 	printf("a = %d ---- id = %d\n", stack->a->val, stack->a->id);
	// 	stack->a = stack->a->next;
	// }
	// while (stack->b)
	// {
	// 	printf("b = %d ---- id = %d| ck_id = %d\n", stack->b->val, stack->b->id, stack->b->chunk_id);
	// 	stack->b = stack->b->next;
	// }
	printf("finishaa--");
	return (0);
}
