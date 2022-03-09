/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:15:37 by ebondi            #+#    #+#             */
/*   Updated: 2022/03/09 17:54:36 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(ps_struct *box)
{
	int	temp;
	int	i;

	temp = box->stack_a[0];
	box->len_a--;
	i = 0;
	while(i < box->len_a)
	{
		box->stack_a[i] = box->stack_a[i + 1];
		i++;
	}
	box->len_b++;
	i = box->len_b - 1;
	while (i > 0)
	{
		box->stack_b[i] = box->stack_b[i - 1];
		i--;		
	}
	box->stack_b[0] = temp;
	write (1, "pb\n", 3);
}

void	pa(ps_struct *box)
{
	int	temp;
	int	i;

	temp = box->stack_b[0];
	box->len_b--;
	i = 0;
	while(i < box->len_b)
	{
		box->stack_b[i] = box->stack_b[i + 1];
		i++;
	}
	box->len_a++;
	i = box->len_a - 1;
	while (i > 0)
	{
		box->stack_a[i] = box->stack_a[i - 1];
		i--;		
	}
	box->stack_a[0] = temp;
	write (1, "pa\n", 3);
}

void	ra(ps_struct *box)
{
	int temp;
	int	i;

	temp = box->stack_a[0];
	i = 0;
	while (i < box->len_a - 1)
	{
		box->stack_a[i] = box->stack_a[i + 1];
		i++;
	}
	box->stack_a[i] = temp;
}


void	rb(ps_struct *box)
{
	int temp;
	int	i;

	temp = box->stack_b[0];
	i = 0;
	while (i < box->len_b - 1)
	{
		box->stack_b[i] = box->stack_b[i + 1];
		i++;
	}
	box->stack_b[i] = temp;
}

void	ss(ps_struct *box)
{
	ft_swap(&box->stack_a[0], &box->stack_a[1]);
	ft_swap(&box->stack_b[0], &box->stack_b[1]);
	write (1, "ss\n", 3);
}