/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:12:57 by noam              #+#    #+#             */
/*   Updated: 2024/03/21 18:18:55 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

static	int	calculate_cost(int a_rot, int b_rot)
{
	if (a_rot >= 0 && b_rot >= 0)
	{
		if (a_rot > b_rot)
			return (a_rot);
		else
			return (b_rot);
	}
	else if (a_rot < 0 && b_rot < 0)
	{
		if (a_rot < b_rot)
			return (a_rot * -1);
		else
			return (b_rot * -1);
	}
	else
	{
		if (a_rot <= 0 && b_rot >= 0)
			return ((a_rot * -1) + b_rot);
		else
			return (a_rot + (b_rot * -1));
	}
}

/* ************************************************************************** */
/*
NEED TO DO CALCULATE COST AGAIN (BECAUSE WHAT IF A_ROT AND B_ROT ARE 0 ????)
*/
/* ************************************************************************** */

static	int	is_cheaper(t_stack **node, t_stack **target_node)
{
	int	node_cost;
	int	target_cost;

	node_cost = calculate_cost((*node)->a_rot, (*node)->b_rot);
	// printf("node_cost = %d\n", node_cost);
	target_cost = calculate_cost((*target_node)->a_rot, (*target_node)->b_rot);
	// printf("target_cost = %d\n", target_cost);
	return (node_cost < target_cost);
}

t_stack	*find_cheapest_node(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*cheapest;

	tmp = *b;
	cheapest = *b;
	tmp = tmp->next;
	while (tmp != *b)
	{
		if (is_cheaper(&tmp, &cheapest))
		{
			cheapest = tmp;
		}
		tmp = tmp->next;
	}
	return (cheapest);
}

