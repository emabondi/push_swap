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

int	**matrix_init(ps_struct *box)
{
	int	**matrix;

	matrix = (int **) malloc (sizeof(int *) * box->len_a);
	ft_check_malloc(matrix);
	matrix[0] = (int *) malloc (sizeof(int) * 1);
	ft_check_malloc(matrix[0]);
	matrix[0][0] = 1;
	return (matrix);
}

void	lis(ps_struct *box)
{
	int **matrix;
	int	ind_min;
	int	j;
	int	i;

	matrix = matrix_init(box);
	ind_min = find_ind_min(box);
	j = 1;
	i = ind_min + 1;
	if (i == box->len_a)
		i = 0;
	while (i != ind_min)
	{
		if (box->stack_a[i] > matrix[j - 1][j - 1])
			matrix[j - 1] = extend_matrix(matrix[j - 1], &j, box->stack_a[i]);
		else
			ft_between(matrix, box->stack_a[i]);
		i++;
		if (i == box->len_a)
			i = 0;
	}
	box->lis_size = j;
	box->lis = arr_dup(matrix[j - 1], j);
	free_matrix(matrix, j);
}

int	*extend_matrix(int *arr, int *j, int num)
{
	int	*new_arr;
	int	i;

	new_arr = (int *) malloc (sizeof(int) * (*j + 1));
	ft_check_malloc(new_arr);
	i = 0;
	while (i < *j)
	{
		new_arr[i] = arr[i];
		i++;
	}
	new_arr[i] = num;
	(*j)++;
	return (new_arr);
}

void	ft_between(int **matrix, int num)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i][i] < num)
		i++;
	j = 0;
	while (j < i)
	{
		matrix[i][j] = matrix[i - 1][j];
		j++;
	}
	matrix[i][j] = num;
}
