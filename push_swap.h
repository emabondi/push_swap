/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:43:59 by ebondi            #+#    #+#             */
/*   Updated: 2022/03/26 18:58:08 by marvin           ###   ########.fr       */
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

typedef struct push_swap
{
	int	*stack_a;
	int	*stack_b;
	int	len_a;
	int	len_b;
	int	*lis;
	int	lis_size;
}				ps_struct;

int		ft_atoi(const char *str);
int		check_stacks(ps_struct *box);
int		ft_check(char *num);
int		fill_stack_a(ps_struct *box, char *argv[]);
void	renumber_stack(ps_struct *box);
void	ft_swap(int *num1, int *num2);
void	ft_check_malloc(void *ptr);
void	renumber_stack_a(ps_struct *box, int *temp);
int		**matrix_init(ps_struct *box);
int		*extend_matrix(int *arr, int *j, int num);
void	ft_between(int **matrix, int num);
int		ft_go_away(ps_struct *box, int num);
int		find_ind(int *arr, int size_arr, int num);
void	pb(ps_struct *box);
void	pa(ps_struct *box);
void	ra(ps_struct *box);
void	rb(ps_struct *box);
void	ss(ps_struct *box);
void	rr(ps_struct *box);
void	rra(ps_struct *box);
void	rrb(ps_struct *box);
void	rrr(ps_struct *box);
int		*lis(ps_struct *box);
int		find_ind_min(ps_struct *box);
void	push_chunk_b(ps_struct *box);
void	ft_printarray(int *ar, int size);
int		ft_order(int *ar, int size);
void	push_swap(ps_struct *box);
t_best	*find_best_move(ps_struct *box);
void	find_best_a(t_best *best, ps_struct *box);
void	find_best_a_2(t_best *best, ps_struct *box, int j);
void	count_moves(t_best *best);
void	do_push_swap(t_best min, ps_struct *box);

#endif
