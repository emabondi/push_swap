/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:58:35 by marvin            #+#    #+#             */
/*   Updated: 2022/03/25 17:58:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_order(int *ar, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (ar[i] > ar[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_go_away(ps_struct *box, int num)
{
	int	i;

	i = 0;
	while(box->stack_a[i] != num)
		i++;
	while (box->stack_a[0] != num)
	{
		if (i <= box->len_a / 2)
		{
			ra(box);
			write (1, "ra\n", 3);
		}
		else
		{
			rra(box);
			write (1, "rra\n", 4);
		}
	}
	pb(box);
}

int	find_ind(int *arr, int size_arr, int num)
{
	int	i;

	i = 0;
	while (i < size_arr)
	{
		if (arr[i] == num)
			return (i);
		i++;
	}
	return (-1);
}


void	find_best_a_2(t_best *best, ps_struct *box, int j)
{
	best->insertion_point = box->stack_a[j];
	best->n_move_insertion = j;	
	best->dir_a = 0;
		if (j > box->len_a / 2)
		{
			best->dir_a = 1;
			best->n_move_insertion = box->len_a - j;
		}
}

void	count_moves(t_best *best)
{
	if (best->dir_a == best->dir_b)
	{
		if (best->n_move > best->n_move_insertion)
			best->total_moves = best->n_move;
		else
			best->total_moves = best->n_move_insertion;
	}
	else
		best->total_moves = best->n_move_insertion + best->n_move;
}