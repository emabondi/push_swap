/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:45:51 by ebondi            #+#    #+#             */
/*   Updated: 2022/03/10 19:12:49 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	push_chunk_b(ps_struct *box)
{
	int	average;
	int	init_average;
	int	i;

	average = box->len_a / 4;
	init_average = average;
	while (box->len_a != box->lis_size && average != 0)
	{
		i = 0;
		while (i < box->len_a)
		{
			if (find_ind(box->lis, box->lis_size, box->stack_a[i]) == -1 && box->stack_a[i] <= average)
			{
				ft_go_away(box, box->stack_a[i]);
				i = -1;
			}
			i++;
		}
		average += init_average;
	}
	// printf("A:\n");
	// ft_printarray(box->stack_a, box->len_a);
	// printf("B:\n");
	// ft_printarray(box->stack_b, box->len_b);
}

void	push_swap(ps_struct *box)
{
	t_best	*best;
	t_best	min;
	int		i;

	while (box->len_b != 0)
	{
		best = find_best_move(box);
		min = best[0];
		i = 1;
		while (i < box->len_b)
		{
			if (best[i].total_moves < min.total_moves)
				min = best[i];
			i++;
		}
		do_push_swap(min, box);
	}
}

t_best	*find_best_move(ps_struct *box)
{
	int	i;
	t_best	*best;

	best = (t_best *) malloc (sizeof(t_best) * box->len_b);
	ft_check_malloc (best);
	i = 0;
	while (i < box->len_b)
	{
		best[i].num = box->stack_b[i];
		best[i].n_move = i;
		best[i].dir_b = 0;
		if (i > box->len_b / 2)
		{
			best[i].dir_b = 1;
			best[i].n_move = box->len_b - i;
		}
		find_best_a(&best[i], box);
		count_moves(&best[i]);
		i++;
	}
	return (best);
}

void	find_best_a(t_best *best, ps_struct *box)
{
	int	i;
	int	j;
	int x;

	i = 0;
	while (i < box->len_a)
	{
		j = i + 1;
		if (j == box->len_a)
			j = 0;
		if (box->stack_a[i] < best->num && box->stack_a[j] > best->num)
		{
			find_best_a_2(best, box, j);
			return ;
		}
		if (box->stack_a[i] == 1)
			x = i;
		i++;
	}
	best->insertion_point = 1;
	best->n_move_insertion = x;
	best->dir_a = 0;
	if (x > box->len_a / 2)
	{
		best->dir_a = 1;
		best->n_move_insertion = box->len_a - x;
	}
}

void	do_push_swap(t_best min, ps_struct *box)
{
	while (box->stack_a[0] != min.insertion_point && box->stack_b[0] != min.num && min.dir_a == min.dir_b)
	{
		if (min.dir_a == 0)
			rr(box);
		else
			rrr(box);
	}
	while (box->stack_a[0] != min.insertion_point && min.dir_a == 0)
	{
		ra(box);
		write (1, "ra\n", 3);
	}
	while (box->stack_b[0] != min.num && min.dir_b == 0)
	{
		rb(box);
		write (1, "rb\n", 3);
	}
	while (box->stack_a[0] != min.insertion_point && min.dir_a == 1)
	{
		rra(box);
		write (1, "rra\n", 4);
	}
	while (box->stack_b[0] != min.num && min.dir_b == 1)
	{
		rrb(box);
		write (1, "rrb\n", 4);
	}
	pa(box);
}
