/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:43:59 by ebondi            #+#    #+#             */
/*   Updated: 2022/05/03 12:23:12 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>

typedef struct s_best
{
	int	num;
	int	n_move;
	int	dir_b;
	int	insertion_point;
	int	n_move_insertion;
	int	dir_a;
	int	total_moves;
}				t_best;

typedef struct s_pushswap
{
	int	*stack_a;
	int	*stack_b;
	int	len_a;
	int	len_b;
	int	*lis;
	int	lis_size;
}				t_struct;

int		ft_atoi(const char *str);
int		check_stacks(t_struct *box);
int		ft_check(char *num);
int		fill_stack_a(t_struct *box, char *argv[], int flag);
void	renumber_stack(t_struct *box);
void	ft_swap(int *num1, int *num2, int size);
void	ft_check_malloc(void *ptr);
void	renumber_stack_a(t_struct *box, int *temp);
int		**matrix_init(t_struct *box);
int		*extend_matrix(int *arr, int *j, int num);
void	ft_between(int **matrix, int num);
void	ft_go_away(t_struct *box, int num);
int		find_ind(int *arr, int size_arr, int num);
void	pb(t_struct *box);
void	pa(t_struct *box);
void	ra(t_struct *box);
void	rb(t_struct *box);
void	ss(t_struct *box);
void	rr(t_struct *box);
void	rra(t_struct *box);
void	rrb(t_struct *box);
void	rrr(t_struct *box);
void	lis(t_struct *box);
int		find_ind_min(t_struct *box);
void	push_chunk_b(t_struct *box);
void	ft_printarray(int *ar, int size);
int		ft_order(int *ar, int size);
void	push_swap(t_struct *box);
t_best	*find_best_move(t_struct *box);
void	find_best_a(t_best *best, t_struct *box);
void	find_best_a_2(t_best *best, t_struct *box, int j);
void	count_moves(t_best *best);
void	do_push_swap(t_best min, t_struct *box);
void	one_first(t_struct *box);
char	**ft_split(char const *s, char c);
void	ft_error(void);
int		count_stack(char **args);
char	*get_next_line(int fd);
int		ft_strcpy(char *s1, char *s2);
void	ft_strcpy2(char *save, char *str, int i);
int		ft_findchr(const char *s, char c);
char	*ft_save(char *str);
void	checker_pb(t_struct *box);
void	checker_pa(t_struct *box);
int		*arr_dup(int *arr, int len);
void	free_matrix(int **matrix, int size);
void	main_checker2(t_struct *box);
void	do_push_swap2(t_best min, t_struct *box);
void	find_best_a_3(t_best *best, t_struct *box, int x);

#endif
