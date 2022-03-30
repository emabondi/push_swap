/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:56:17 by ebondi            #+#    #+#             */
/*   Updated: 2022/03/27 17:56:17 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(ps_struct *box)
{
	ra(box);
	rb(box);
	write (1, "rr\n", 3);
}

void	rra(ps_struct *box)
{
	int temp;
	int	i;

	if (box->len_a <= 1)
		ft_error ();
	i = box->len_a - 1;
	temp = box->stack_a[i];
	while (i > 0)
	{
		box->stack_a[i] = box->stack_a[i - 1];
		i--;
	}
	box->stack_a[i] = temp;
}

void	rrb(ps_struct *box)
{
	int temp;
	int	i;

	if (box->len_b <= 1)
		ft_error ();
	i = box->len_b - 1;
	temp = box->stack_b[i];
	while (i > 0)
	{
		box->stack_b[i] = box->stack_b[i - 1];
		i--;
	}
	box->stack_b[i] = temp;
}

void	rrr(ps_struct *box)
{
	rra(box);
	rrb(box);
	write (1, "rrr\n", 4);
}