/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array_sorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 03:42:37 by noam              #+#    #+#             */
/*   Updated: 2024/03/12 13:11:37 by noam             ###   ########.fr       */
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

int	*strings_to_int_array(char **tab, int len)
{
	int	*array;


	array = (int *)malloc(sizeof(int) * len);
	if (!array)
		return (NULL);
	while (--len >= 0)
		array[len] = ft_atol(tab[len]);
	return (array);
}

int	*int_array_sorted(char **tab, int len)
{
	int	*array;

	array = strings_to_int_array(tab, len);
	ft_quicksort(array, 0, len -1);
	return (array);
}