/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:02:51 by ebondi            #+#    #+#             */
/*   Updated: 2022/05/03 12:31:37 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_best_a_3(t_best *best, t_struct *box, int x)
{
	best->insertion_point = 1;
	best->n_move_insertion = x;
	best->dir_a = 0;
	if (x > box->len_a / 2)
	{
		best->dir_a = 1;
		best->n_move_insertion = box->len_a - x;
	}
}

void	do_push_swap2(t_best min, t_struct *box)
{
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
}

void	main_checker2(t_struct *box)
{
	if (ft_order(box->stack_a, box->len_a) == 1)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free (box->stack_a);
	free (box->stack_b);
}
