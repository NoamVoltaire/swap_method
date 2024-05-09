/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_min_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:48:52 by noam              #+#    #+#             */
/*   Updated: 2024/05/09 16:09:41 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_header.h"

static	int	find_low(t_stack *tmp, t_global global)
{
	int	i;

	i = 0;
	while (tmp->content != global.low)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	go_to_min_node(t_stack **a, t_global *global)
{
	int		nb_ra;
	int		nb_rra;

	nb_ra = find_low(*a, *global);
	nb_rra = global->len_a - nb_ra;
	if (nb_ra > nb_rra)
		nb_ra = 0;
	else
		nb_rra = 0;
	while (nb_ra > 0)
	{
		rotate(a, 'a', global);
		nb_ra--;
	}
	while (nb_rra > 0)
	{
		reverse_rotate(a, 'a', global);
		nb_rra--;
	}
}
