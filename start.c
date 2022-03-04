/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:43:28 by ebondi            #+#    #+#             */
/*   Updated: 2022/03/04 20:11:47 by ebondi           ###   ########.fr       */
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
	if(!check_stacks(&box, argv))
	{
		write (1, "ERROR\n", 6);
		return (0);
	}
	box.stack_a = (int *) malloc (sizeof(int) * box.len_a);
	box.stack_b = (int *) malloc (sizeof(int) * box.len_a);

}

int	check_stacks(ps_struct *box, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i <= box->len_a)
	{
		if(!ft_check(argv[i]))
			return (0);
		j = i + 1;
		while (j <= box->len_a)
		{
			if (*argv[i] == *argv[j])
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