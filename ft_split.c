/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebondi <ebondi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:48:20 by ebondi            #+#    #+#             */
/*   Updated: 2022/03/27 18:48:20 by ebondi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rowcount(char const *str, char c)
{
	int	i;
	int	count;

	if (str == NULL)
		return (0);
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			count += 1;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

static int	ft_rowlen(char const *str, char c)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static int	ft_putstr(char *matrix, char const *str, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		matrix[j] = str[i];
		i++;
		j++;
	}
	matrix[j] = '\0';
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		count;
	int		len;
	int		row;

	count = ft_rowcount(s, c);
	if (count == 0)
		return (NULL);
	matrix = (char **) malloc (sizeof(char *) * (count + 1));
	ft_check_malloc(matrix);
	matrix[count] = NULL;
	len = 0;
	row = 0;
	while (row < count)
	{
		len = ft_rowlen(s, c);
		matrix[row] = (char *) malloc (sizeof(char) * (len + 1));
		s += ft_putstr(matrix[row], s, c);
		row++;
	}
	return (matrix);
}
