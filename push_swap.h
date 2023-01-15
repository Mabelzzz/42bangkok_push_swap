#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

// # include "get_next_line/get_next_line.h"
typedef struct s_list
{
	int				val;
	int				id;
	int				i;
	struct s_list	*next;
}	t_list;

typedef struct s_stc
{
	char	***tmp;
	int		cnt;
	int		x;
	int		y;
	int		z;
	int		chunk;
	int		range;
	int		min;
	int		push;
	int		med;
	int		len;
	int		round;
	t_list	*a;
	t_list	*b;
}	t_stc;

typedef struct s_wd
{
	char	*word;

}	t_wd;

// check_error.c
void	check_nbr(char *s, t_stc *stack);
int		check_duplicate(t_list **stack);

// ft_split.c
size_t	cnt_alphabet(char *s, char c);
char	*keep_alphabet(char *s, char c);
size_t	cnt_word(char *s, char c);
char	**ft_split(char *s, char c);

// get_input.c
void	get_val(t_stc *stack, int argc, char **argv);
void	get_list(t_stc *stack);

// oprt_push.c
t_list	*push(t_list **stack);
void	pa(t_stc *stack);
void	pb(t_stc *stack);

// oprt_rerotate.c
void	reverse_rotate(t_list **lst, char st);
// void	rra(t_stc *stack);
// void	rrb(t_stc *stack);
void	rrr(t_stc *stack);

// oprt_rotate.c
void	rotate(t_list **lst, char st);
// void	ra(t_stc *stack);
// void	rb(t_stc *stack);
void	rr(t_stc *stack);

// oprt_swap.c
void	swap(t_list **lst, char st);
// void	sa(t_stc *stack);
// void	sb(t_stc *stack);
void	ss(t_stc *stack);

// push_swap.c
void	init(t_stc *stack);
void	sort_bylen_min(t_stc *stack, t_list **lst, char st, int len);
void	sort_bylen_max(t_stc *stack, t_list **lst, char st, int len);
// sort_bylen(t_stc *stack, int len);
void	sort_ab(t_stc *stack, int c);
void	sort_a(t_stc *stack, t_list *a, t_list *l_a, int c);
void	sort_b(t_stc *stack, t_list *b, t_list *l_b, int c);
int		check_sort(t_list *lst);

// sort_three.c
void	sort_two_min(t_list **lst, char st);
void	sort_two_max(t_list **lst, char st);
void	sort_three_min(t_stc *stack, t_list **lst, char st);
void	sort_three_max(t_stc *stack, t_list **lst, char st);

void	set_val(t_stc *stack, char st);
void	set_index(t_stc *stack);

// sort_hundred.c
void	sort_hundred(t_stc *stack, t_list **lst, char st);
void	sort_hund(t_stc *stack, t_list **lst, char st);
int		quick_sort_pb(t_stc *stack, t_list **lst, char st);
int		quick_sort_pa(t_stc *stack, t_list **lst, char st);
void	find_max(t_stc *stack);
void	push_b(t_stc *stack, int ck);
void	send_back_a(t_stc *stack);
void	send_back_b(t_stc *stack);

// sort_five.c
void	sort_four(t_stc *stack, int min);
void	sort_five(t_stc *stack, int min);
void	sort_ten(t_stc *stack, int min);
void	push_min_b(t_stc *stack, int id);

// utils.c
int		ft_atoi (char *s);
void	putstr(char *str);
void	put_st(char st);
void	error(void);
void	error_free(t_stc *stack);
void	free_stack_tmp(t_stc *stack);
void	free_lst(t_list *lst);

// utils_list.c
t_list	*ft_lstlast(t_list *lst);
// t_list	*ft_lstnew(int val);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);

#endif
