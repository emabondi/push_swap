/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:43:28 by ebondi            #+#    #+#             */
/*   Updated: 2022/03/10 15:39:23 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	ps_struct	box;
	int			i;

	if (argc <= 1)
		write(1, "Arguments not inserted\n", 23);
	if (argc <= 1)
		return (0);
	box.len_a = argc - 1;
	box.len_b = 0;
	box.stack_a = (int *) malloc (sizeof(int) * box.len_a);
	ft_check_malloc(box.stack_a);
	box.stack_b = (int *) malloc (sizeof(int) * box.len_a);
	ft_check_malloc(box.stack_b);
	if(!fill_stack_a(&box, argv))
	{
		write (1, "Error\n", 6);
		return (0);
	}
	renumber_stack(&box);
	divide_stack(&box);
	ft_push_swap(&box);
	push_a(&box);
	//i = 0;
	//while (i < box.len_a)
	//{
	//	printf("%d ", box.stack_a[i]);
	//	i++;
	//}
	//i = 0;
	//printf ("\n");
	//while (i < box.len_b)
	//{
	//	printf("%d ", box.stack_b[i]);
	//	i++;
	//}
}

void	renumber_stack(ps_struct *box)
{
	int *temp;
	int	i;
	int	j;

	temp = (int *) malloc (sizeof(int) * box->len_a);
	ft_check_malloc(temp);
	i = 0;
	while (i < box->len_a)
	{
		temp[i] = box->stack_a[i];
		i++;
	}
	while (i > 0)
	{
		j = 0;
		while (j < box->len_a - 1)
		{
			if (temp[j] > temp[j + 1])
				ft_swap(&temp[j], &temp[j + 1]);
			j++;
		}
		i--;
	}
	renumber_stack_a(box, temp);
	free (temp);
}

int	fill_stack_a(ps_struct *box, char *argv[])
{
	int	i;

	i = 0;
	while(i < box->len_a)
	{
		if (!ft_check(argv[i + 1]))
			return (0);
		box->stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	if(!check_stacks(box))
		return (0);
	return (1);
}

int	check_stacks(ps_struct *box)
{
	int	i;
	int	j;

	i = 0;
	while (i < box->len_a)
	{
		j = i + 1;
		while (j < box->len_a)
		{
			if (box->stack_a[i] == box->stack_a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '+' || num[0] == '-')
		i++;
	if (num[i] == '\0')
		return (0);
	while (num[i] != '\0')
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);
		i++;		
	}
	return (1);
}