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

void	ft_push_swap(ps_struct *box)
{
	int	i;
	
	while ((!a_ordered(box) || !b_ordered(box)))
	{
		if (box->stack_a[0] > box->stack_a[1] && box->stack_b[0] < box->stack_b[1] && box->stack_a[0] != box->max && box->stack_b[0] != 1)
			ss(box);
		else if ((box->stack_a[0] < box->stack_a[1] && box->stack_b[0] > box->stack_b[1]) || (box->stack_a[0] == box->max && box->stack_b[0] == 1))
			rr(box);
		else if (box->stack_a[0] > box->stack_a[1] && box->stack_a[0] != box->max)
		{
			ft_swap(&box->stack_a[0], &box->stack_a[1]);
			write (1, "sa\n", 3);
		}
		else if (box->stack_b[0] < box->stack_b[1] && box->stack_b[0] != 1)
		{
			ft_swap(&box->stack_b[0], &box->stack_b[1]);
			write (1, "sb\n", 3);
		}
		else if (box->stack_a[0] < box->stack_a[1] || box->stack_a[0] == box->max)
		{
			ra(box);
			write (1, "ra\n", 3);
		}
		else if (box->stack_b[0] > box->stack_b[1] || box->stack_b[0] == 1)
		{
			rb(box);
			write (1, "rb\n", 3);
		}
	}
}

int	a_ordered(ps_struct *box)
{
	int	i;

	i = 0;
	while (i < box->len_a - 1)
	{
		if (box->stack_a[i] > box->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	b_ordered(ps_struct *box)
{
	int	i;

	i = 0;
	while (i < box->len_b - 1)
	{
		if (box->stack_b[i] < box->stack_b[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	rr(ps_struct *box)
{
	ra(box);
	rb(box);
	write (1, "rr\n", 3);
}

void	push_a(ps_struct *box)
{
	while (box->len_b)
		pa(box);
}