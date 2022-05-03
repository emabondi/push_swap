/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:08:01 by ebondi            #+#    #+#             */
/*   Updated: 2022/03/30 18:08:01 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_2(t_struct *box)
{
	if ((box->stack_a[0] == 1 || box->stack_a[1] == 2
			|| box->stack_a[2] == 3) && box->stack_a[0] != 4
		&& box->stack_a[2] != 5
		&& ft_order(box->stack_a, box->len_a) == 0)
	{
		ft_swap(&box->stack_a[0], &box->stack_a[1], box->len_a);
		write(1, "sa\n", 3);
	}
	lis(box);
	push_chunk_b(box);
	push_swap(box);
	one_first(box);
	free (box->stack_a);
	free (box->stack_b);
	free (box->lis);
}

int	main(int argc, char *argv[])
{
	t_struct	box;
	int			flag;

	if (argc <= 1)
		ft_error();
	box.len_a = argc - 1;
	box.len_b = 0;
	flag = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (argv == NULL)
			ft_error();
		box.len_a = count_stack(argv);
		flag = 0;
	}
	box.stack_a = (int *) malloc (sizeof(int) * box.len_a);
	ft_check_malloc(box.stack_a);
	box.stack_b = (int *) malloc (sizeof(int) * box.len_a);
	ft_check_malloc(box.stack_b);
	if (!fill_stack_a(&box, &argv[flag], flag))
		ft_error();
	renumber_stack(&box);
	main_2(&box);
}
