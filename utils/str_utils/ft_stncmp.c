/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stncmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:02:27 by noam              #+#    #+#             */
/*   Updated: 2024/03/11 22:02:40 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap_header.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		sum;

	i = 0;
	sum = 0;
	while ((s1[i] || s2[i]) && sum == 0 && (i < n))
	{
		sum = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
		i++;
	}
	return (sum);
}