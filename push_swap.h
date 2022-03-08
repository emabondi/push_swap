/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:43:59 by ebondi            #+#    #+#             */
/*   Updated: 2022/03/08 17:04:36 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include<unistd.h>
#include<stdlib.h>

typedef struct push_swap
{
	int	*stack_a;
	int	*stack_b;
	int	len_a;
	int	len_b;
	int	max;
	int	half;
}				ps_struct;

int		ft_atoi(const char *str);
int		check_stacks(ps_struct *box);
int		ft_check(char *num);
int		fill_stack_a(ps_struct *box, char *argv[]);
void	renumber_stack(ps_struct *box);
void	ft_swap(int *num1, int *num2);
void	ft_check_malloc(void *ptr);
void	renumber_stack_a(ps_struct *box, int *temp);
void	pb(ps_struct *box);
void	pa(ps_struct *box);

#endif
