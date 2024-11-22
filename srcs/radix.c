/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:02:22 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/26 12:55:07 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	get_max(t_stack *head)
{
	long	max;

	max = head->nb;
	while (head)
	{
		if (head->nb > max)
			max = head->nb;
		head = head->next;
	}
	return (max);
}

int	stack_length(t_stack *head)
{
	int	length;

	length = 0;
	while (head)
	{
		length++;
		head = head->next;
	}
	return (length);
}

void	radix_sort(t_stacks *stacks)
{
	long	max;
	int		max_bits;
	int		i;
	int		j;
	int		len;

	max = get_max(stacks->head_a);
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		len = stack_length(stacks->head_a);
		j = 0;
		while (j++ < len)
		{
			if (((stacks->head_a->nb >> i) & 1) == 1)
				ra(stacks);
			else
				pb(stacks);
		}
		while (stacks->head_b)
			pa(stacks);
	}
}
