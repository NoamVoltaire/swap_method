/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somet_type_of_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:06:53 by noam              #+#    #+#             */
/*   Updated: 2024/03/17 16:26:10 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

void	somet_type_of_sort(t_stack **a, t_stack **b, t_global *limits)
{
		
	limits->mid  = (limits->start + limits->end) / 2;
	limits->second_mid = (limits->mid + limits->end) / 2;
	if (limits->start >= limits->end)
		return ;
	push_halves(a, b, limits);
}