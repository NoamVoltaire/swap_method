/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 00:07:32 by noam              #+#    #+#             */
/*   Updated: 2024/03/25 02:32:32 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

static	int	is_lowest_three(int nb, t_global *global)
{
	return (nb == global->low || nb == global->sorted[1]
		|| nb == global->sorted[2]);
}

static	void	find_nearest_low(t_stack **a, t_global *global)
{
	if (is_lowest_three((*a)->next->content, global))
		rotate(a, 'a', global);
	else if (is_lowest_three((*a)->prev->content, global))
		reverse_rotate(a, 'a', global);
	else if (is_lowest_three((*a)->next->next->content, global))
	{
		rotate(a, 'a', global);
		rotate(a, 'a', global);
	}
	else if (is_lowest_three((*a)->prev->prev->content, global))
	{
		reverse_rotate(a, 'a', global);
		reverse_rotate(a, 'a', global);
	}
}

static	void	minisort(t_stack **a, t_stack **b, t_global *global)
{
	while (global->len_a > 3)
	{
		if (is_lowest_three((*a)->content, global))
		{
			push(a, b, 'b', global);
		}
		else
		{
			find_nearest_low(a, global);
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
	if (global->len_a == 2)
	{
		if ((*a)->content == global->high)
			swap(a, 'a', global);
	}
	if (global->len_a == 3)
		sort_three(a, 'a', global);
	if (global->len_a > 3 && global->len_a <= 6)
		minisort(a, b, global);
	if (global->len_a > 6)
		sort_algo(a, b, global);
}
