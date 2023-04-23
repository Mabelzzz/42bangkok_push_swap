/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <pnamwayk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:58:56 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/04/23 14:38:29 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../gnl/get_next_line.h"

typedef struct s_list
{
	int				val;
	int				id;
	struct s_list	*next;
}	t_list;

typedef struct s_stc
{
	char	***tmp;
	int		cnt;
	int		x;
	int		y;
	int		z;
	int		chunk_size;
	int		chunk;
	int		range;
	int		min;
	int		max;
	int		size_a;
	int		size_b;
	int		lower;
	int		upper;
	int		med;
	int		len;
	int		pb_cnt;
	int		pa_cnt;
	int		ra_cnt;
	int		rb_cnt;
	int		tmp_sz;
	t_list	*a;
	t_list	*b;
}	t_stc;

// check_error.c
void	error(void);
void	error_free(t_stc *stack);
void	check_nbr(char *s, t_stc *stack);
int		check_duplicate(t_list **stack);

// check_sort.c
int		check_sort(t_list *lst);
int		check_sort_min(t_list *tmp, int len);
int		check_sort_max(t_list *tmp, int len);

// checker.c
void	init_checker(t_stc *stack);
void	read_oprt(t_stc *stack);
int		check_stack(t_stc *stack, char *str, size_t len);
int		check_stack2(char *str, int size_a, int size_b);

// chunk_sort.c
void	chunk_sort(t_stc *stack, int size);
void	send_to_b(t_stc *stack);
void	sort_b(t_stc *stack, int f);
void	send_to_a(t_stc *stack, int id);

// find_id.c
int		find_id(t_list *lst, int id);
int		find_less_upper(t_list *lst, int upper);

// ft_atoi.c
int		ft_atoi(char *s, t_stc *stack);

// ft_split.c
char	**ft_split(t_stc *stack, char *s, char c);
char	**keep_word(char **word, char *s, char c);
char	*keep_alphabet(char *s, char c);
size_t	cnt_alphabet(char *s, char c);
size_t	cnt_word(char *s, char c);

// ft_strncmp.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// get_input.c
void	get_val(t_stc *stack, int argc, char **argv);
void	get_list(t_stc *stack);
t_list	*get_tmp(t_list *tmp, t_stc *stack, int i, int j);

// oprt_push.c
t_list	*push(t_list **stack);
void	pa(t_stc *stack);
void	pb(t_stc *stack);

// oprt_rerotate.c
void	reverse_rotate(t_list **lst);
void	rra(t_stc *stack);
void	rrb(t_stc *stack);
void	rrr(t_stc *stack);

// oprt_rotate.c
void	rotate(t_list **lst);
void	ra(t_stc *stack);
void	rb(t_stc *stack);
void	rr(t_stc *stack);

// oprt_swap.c
void	swap(t_list **lst);
void	sa(t_stc *stack);
void	sb(t_stc *stack);
void	ss(t_stc *stack);

// push_swap.c
void	init_push_swap(t_stc *stack);
void	sort_by_len_a(t_stc *stack, t_list **lst, int len);

// quick_sort_a.c
void	quicksort_a(t_list **lst, t_stc *stack, int size);
void	set_value_qsa(t_stc *stack, int size);
void	qsa(t_stc *stack);
void	sort_small(t_stc *stack, int size, int i);

// quick_sort_b.c
void	quicksort_b(t_list **lst, t_stc *stack, int size);
void	set_value_qsb(t_stc *stack, int size);
void	qsb(t_stc *stack);

// run_checker.c
void	oprt_ss(t_stc *stack);
void	oprt_rr(t_stc *stack);
void	oprt_rrr(t_stc *stack);
int		find_oprt(char *line, size_t len);
void	run_oprt(t_stc *stack, char *oprt);

// set_val.c
void	set_val(t_stc *stack, char st);
void	set_index(t_list *stack);

// sort_ten.c
void	sort_ten(t_stc *stack, int min);
void	push_min_b(t_stc *stack, int id);
void	push_id_b(t_stc *stack, t_list *tmp, int id);
void	push_id_a(t_stc *stack, t_list *tmp, int id);

// sort_three.c
void	sort_3a(t_stc *stack);
void	sort_3a_top(t_stc *stack);
void	sort_3b_top(t_stc *stack);
void	sort_3b_bottom(t_stc *stack);

// sort_two.c
void	sort_2a(t_stc *stack);
void	sort_2b(t_stc *stack);

// utils_lst.c
void	free_lst(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int val);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);

// utils.c
void	ft_putstr(char *str);
void	ft_putstr_err(char *str);
void	free_stack_tmp(t_stc *stack);
int		stack_size(t_list *stc);
void	find_min_max_idex(t_list *stc, t_stc *stack, int len);

#endif
