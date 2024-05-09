/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:18:56 by noam              #+#    #+#             */
/*   Updated: 2024/05/09 16:14:27 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_header.h"

int	lst_len(t_stack *stack)
{
	int		len;
	t_stack	*tmp;
	t_stack	*end;

	len = 0;
	if (!stack)
		return (0);
	end = stack->prev;
	tmp = stack;
	while (tmp != end)
	{
		len++;
		tmp = tmp->next;
	}
	return (len + 1);
}
