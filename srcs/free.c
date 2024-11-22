/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:57:12 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/25 23:41:13 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		free(array[i++]);
	free(array);
}

// deallocate my stacks
void	deallocate(t_stack **head, t_stack **tail)
{
	t_stack	*curr;

	if (*head == NULL)
		return ;
	curr = *head;
	while (curr->next != NULL)
	{
		curr = curr->next;
		free(curr->prev);
	}
	free(curr);
	*head = NULL;
	*tail = NULL;
}

void	deallocate_stacks(t_stacks *stacks)
{
	deallocate(&stacks->head_a, &stacks->tail_a);
	deallocate(&stacks->head_b, &stacks->tail_b);
}
