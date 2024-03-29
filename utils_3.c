/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:55:52 by ebondi            #+#    #+#             */
/*   Updated: 2022/03/27 17:55:52 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	one_first(t_struct *box)
{
	if (find_ind_min(box) <= box->len_a / 2)
	{
		while (box->stack_a[0] != 1)
		{
			ra(box);
			write (1, "ra\n", 3);
		}
	}
	else
	{
		while (box->stack_a[0] != 1)
		{
			rra(box);
			write (1, "rra\n", 4);
		}
	}
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	count_stack(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	return (i);
}

int	*arr_dup(int *arr, int len)
{
	int	*new;
	int	i;

	new = (int *) malloc (sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		new[i] = arr[i];
		i++;
	}
	return (new);
}

void	free_matrix(int **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free (matrix[i]);
		i++;
	}
	free (matrix);
}
