/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:00:21 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/26 15:54:34 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *head)
{
	t_stack	*curr;

	curr = head;
	while (curr != NULL)
	{
		ft_printf("%d\n", curr->nb);
		curr = curr->next;
	}
}

// check if the number are already in ascend order
int	is_sorted(t_stacks *stacks)
{
	int		i;
	t_stack	*curr;

	if (stacks->head_a == NULL)
		return (1);
	curr = stacks->head_a;
	i = curr->nb;
	while (curr)
	{
		if ((i > curr->nb))
			return (0);
		i = curr->nb;
		curr = curr->next;
	}
	return (1);
}
