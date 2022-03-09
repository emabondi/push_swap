/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:59:07 by ebondi            #+#    #+#             */
/*   Updated: 2022/03/09 21:14:46 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	renumber_stack_a(ps_struct *box, int *temp)
{
	int	i;
	int	j;

	i = 0;
	while (i < box->len_a)
	{
		j = 0;
		while (j < box->len_a)
		{
			if (box->stack_a[i] == temp[j])
			{
				box->stack_a[i] = j + 1;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	divide_stack(ps_struct *box)
{
	box->max = box->len_a;
	box->half = box->len_a / 2;
	while (minor_in_a(box))
	{
		if (box->stack_a[0] <= box->half)
			pb(box);
		else
		{
			ra(box);
			write (1, "ra\n", 3);
		}
	}
}

