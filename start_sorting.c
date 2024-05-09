/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 00:07:32 by noam              #+#    #+#             */
/*   Updated: 2024/05/09 16:12:12 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

static	int	biggest_three(int nb, t_global *global, int len)
{
	return (nb == global->high || nb == global->sorted[len - 2]
		|| nb == global->sorted[len - 3]);
}

static	void	find_nearest_low(t_stack **a, t_global *global, int len)
{
	if (!biggest_three((*a)->next->content, global, len))
		rotate(a, 'a', global);
	else if (!biggest_three((*a)->prev->content, global, len))
		reverse_rotate(a, 'a', global);
	else if (!biggest_three((*a)->next->next->content, global, len))
	{
		rotate(a, 'a', global);
		rotate(a, 'a', global);
	}
	else if (!biggest_three((*a)->prev->prev->content, global, len))
	{
		reverse_rotate(a, 'a', global);
		reverse_rotate(a, 'a', global);
	}
}

static	void	minisort(t_stack **a, t_stack **b, t_global *global)
{
	int	len;

	len = global->len_a;
	while (global->len_a > 3)
	{
		if (!biggest_three((*a)->content, global, len))
		{
			push(a, b, 'b', global);
		}
		else
		{
			find_nearest_low(a, global, len);
			push(a, b, 'b', global);
		}
	}
	sort_three(a, 'a', global);
	sort_three(b, 'b', global);
	while (*b)
		push(b, a, 'a', global);
}

void	sort_three(t_stack **lst, char stack, t_global *global)
{
	if (stack == 'a')
	{
		if ((*lst)->content == global->high)
			rotate(lst, 'a', global);
		else if ((*lst)->next->content == global->high)
			reverse_rotate(lst, 'a', global);
		if ((*lst)->content > (*lst)->next->content)
			swap(lst, 'a', global);
	}
	else if (stack == 'b')
	{
		if ((*lst)->content == global->low)
			rotate(lst, 'b', global);
		else if ((*lst)->next->content == global->low)
			reverse_rotate(lst, 'b', global);
		if ((*lst)->content < (*lst)->next->content)
			swap(lst, 'b', global);
	}
}

void	start_sorting(t_stack **a, t_stack **b, t_global *global)
{
	if (stack_is_sorted(a))
		return ;
	if (global->len_a == 2)
	{
		if ((*a)->content == global->high)
			swap(a, 'a', global);
	}
	else if (global->len_a == 3)
		sort_three(a, 'a', global);
	else if (global->len_a > 3 && global->len_a <= 6)
		minisort(a, b, global);
	else if (global->len_a > 6)
		sort_algo(a, b, global);
}
