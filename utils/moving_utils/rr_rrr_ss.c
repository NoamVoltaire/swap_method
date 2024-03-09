/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_rrr_ss.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 02:45:16 by noam              #+#    #+#             */
/*   Updated: 2024/03/07 02:50:33 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_header.h"

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, ' ');
	rotate(b, ' ');
	write(1, "rr\n", 3);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a, ' ');
	reverse_rotate(b, ' ');
	write(1, "rrr\n", 4);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a, ' ');
	swap(b, ' ');
	write(1, "ss\n", 3);
}
