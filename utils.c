/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:11:48 by ebondi            #+#    #+#             */
/*   Updated: 2022/03/08 20:26:42 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	res;

	i = 0;
	s = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			s *= -1;
		i += 1;
	}
	if (str[i] == 43 || str[i] == 45)
		return (0);
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = ((res * 10) + (str[i] - 48));
		i++;
	}
	return (res * s);
}

void	ft_swap(int *num1, int *num2)
{
	int	temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void	ft_check_malloc(void *ptr)
{
	if (ptr == NULL)
		exit (1);
}

int	minor_in_a(ps_struct *box)
{
	int i;

	i = 0;
	while(i < box->len_a)
	{
		if (box->stack_a[i] <= box->half)
			return (1);
		i++;
	}
	return (0);
}