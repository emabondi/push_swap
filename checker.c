/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:28:37 by ebondi            #+#    #+#             */
/*   Updated: 2022/03/30 16:28:37 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	check_move(char *str)
{
	if (ft_strcmp(str, "pa\n") == 0)
		return (1);
	if (ft_strcmp(str, "pb\n") == 0)
		return (1);
	if (ft_strcmp(str, "ra\n") == 0 || ft_strcmp(str, "rr\n") == 0)
		return (1);
	if (ft_strcmp(str, "rb\n") == 0 || ft_strcmp(str, "rr\n") == 0)
		return (1);
	if (ft_strcmp(str, "rra\n") == 0 || ft_strcmp(str, "rrr\n") == 0)
		return (1);
	if (ft_strcmp(str, "rrb\n") == 0 || ft_strcmp(str, "rrr\n") == 0)
		return (1);
	if (ft_strcmp(str, "sa\n") == 0 || ft_strcmp(str, "ss\n") == 0)
		return (1);
	if (ft_strcmp(str, "sb\n") == 0 || ft_strcmp(str, "ss\n") == 0)
		return (1);
	return (0);
}

void	ft_correct(char *str, t_struct *box)
{
	if (check_move(str) == 0)
		ft_error ();
	if (ft_strcmp(str, "pa\n") == 0)
		checker_pa(box);
	if (ft_strcmp(str, "pb\n") == 0)
		checker_pb(box);
	if (ft_strcmp(str, "ra\n") == 0 || ft_strcmp(str, "rr\n") == 0)
		ra(box);
	if (ft_strcmp(str, "rb\n") == 0 || ft_strcmp(str, "rr\n") == 0)
		rb(box);
	if (ft_strcmp(str, "rra\n") == 0 || ft_strcmp(str, "rrr\n") == 0)
		rra(box);
	if (ft_strcmp(str, "rrb\n") == 0 || ft_strcmp(str, "rrr\n") == 0)
		rrb(box);
	if (ft_strcmp(str, "sa\n") == 0 || ft_strcmp(str, "ss\n") == 0)
		ft_swap(&box->stack_a[0], &box->stack_a[1], box->len_a);
	if (ft_strcmp(str, "sb\n") == 0 || ft_strcmp(str, "ss\n") == 0)
		ft_swap(&box->stack_b[0], &box->stack_b[1], box->len_b);
}

void	ft_checker(t_struct *box)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
		{
			free (str);
			break ;
		}
		ft_correct(str, box);
		free (str);
	}
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
	ft_checker(&box);
	main_checker2(&box);
}
