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

// int	main(int argc, char *argv[])
// {
// 	t_struct data;

// 	if (argc <= 1)
// 		return (0);
// 	if (argc == 2)
// 		data.ar_a = ft_mono_init(argv[1], &data.size_a);
// 	else
// 	{
// 		argc -= 1;
// 		if (ft_multi_check(&argv[1], argc) == 0)
// 			ft_error();
// 		data.ar_a = ft_multi_init(&argv[1], argc);
// 		data.size_a = argc;
// 	}
// 	if (ft_checkfordoubles(data.ar_a, data.size_a) == 0)
// 		ft_error();
// 	data.ar_a = ft_trasformer(data.ar_a, data.size_a);
// 	ft_resolve(&data);
// 	free(data.ar_a);
// 	free(data.ar_b);
// 	return (0);
// }

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
				ft_swap(&temp[j], &temp[j + 1], box->len_a);
			j++;
		}
		i--;
	}
	renumber_stack_a(box, temp);
	free (temp);
}

int	fill_stack_a(ps_struct *box, char *argv[], int flag)
{
	int	i;

	i = 0;
	while(i < box->len_a)
	{
		if (!ft_check(argv[i]))
			return (0);
		box->stack_a[i] = ft_atoi(argv[i]);
		if (flag == 0)
			free(argv[i]);
		i++;
	}
	if(!check_stacks(box))
		return (0);
	if (flag == 0)
		free(argv);
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
