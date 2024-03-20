/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 03:42:37 by noam              #+#    #+#             */
/*   Updated: 2024/03/17 02:23:58 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

int	ft_partition(int *array, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	int	tmp;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
		j++;
	}
	tmp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = tmp;
	return (i + 1);
}

void	ft_quicksort(int *array, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = ft_partition(array, low, high);
		ft_quicksort(array, low, pivot - 1);
		ft_quicksort(array, pivot + 1, high);
	}
}

int	*lst_to_int_array(t_stack **a, int len)
{
	t_stack	*tmp;
	int		*array;
	int		i;

	tmp = *a;
	i = 0;
	array = (int *)malloc(sizeof(int) * len);
	if (!array)
		return (NULL);
	while (len > 0)
	{
		array[i] = tmp->content;
		tmp = tmp->next;
		len--;
		i++;
	}
	return (array);
}

int	*int_array_sorted(t_stack **a, int len)
{
	int	*array;

	array = lst_to_int_array(a, len);
	ft_quicksort(array, 0, len -1);
	return (array);
}
