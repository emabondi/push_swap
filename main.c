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

int	main(int argc, char *argv[])
{
	ps_struct	box;
	//int			i;
	int			flag;

	if (argc <= 1)
		ft_error() ;
	box.len_a = argc - 1;
	box.len_b = 0;
	flag = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		box.len_a = count_stack(argv);
		flag = 0;
	}
	box.stack_a = (int *) malloc (sizeof(int) * box.len_a);
	ft_check_malloc(box.stack_a);
	box.stack_b = (int *) malloc (sizeof(int) * box.len_a);
	ft_check_malloc(box.stack_b);
	if(!fill_stack_a(&box, &argv[flag], flag))
		ft_error();
	renumber_stack(&box);
	lis(&box);
	push_chunk_b(&box);
	push_swap(&box);
	one_first(&box);
	free (box.stack_a);
	free (box.stack_b);
	free (box.lis);
	// i = 0;
	// while (i < box.len_a)
	// {
	// 	printf("%d ", box.stack_a[i]);
	// 	i++;
	// }
	// i = 0;
	// printf ("\n");
	// while (i < box.len_b)
	// {
	// 	printf("%d ", box.stack_b[i]);
	// 	i++;
	// }
}
