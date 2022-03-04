/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:43:59 by ebondi            #+#    #+#             */
/*   Updated: 2022/03/04 19:45:32 by ebondi           ###   ########.fr       */
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
}				ps_struct;

int	ft_atoi(const char *str);
int	check_stacks(ps_struct *box, char *argv[]);
int	ft_check(char *num);

#endif
