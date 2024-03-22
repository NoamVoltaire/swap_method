/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_rrr_ss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 02:45:16 by noam              #+#    #+#             */
/*   Updated: 2024/03/21 16:01:47 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_header.h"

void	rr(t_stack **a, t_stack **b, t_global *global)
{
	rotate(a, ' ', global);
	rotate(b, ' ', global);
	global->nb_ops--;
	if (!global->debug)
		write(1, "rr\n", 3);
}

void	rrr(t_stack **a, t_stack **b, t_global *global)
{
	reverse_rotate(a, ' ', global);
	reverse_rotate(b, ' ', global);
	global->nb_ops--;
	if (!global->debug)
		write(1, "rrr\n", 4);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a, ' ');
	swap(b, ' ');
	write(1, "ss\n", 3);
}
