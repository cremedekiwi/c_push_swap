/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:34:32 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/25 20:26:32 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stacks *stacks)
{
	t_stack	*aux;

	if (stacks->head_b == NULL)
		return ;
	aux = stacks->head_b->next;
	if (stacks->tail_a == NULL)
		first_value(&stacks->head_a, &stacks->tail_a, stacks->head_b->nb);
	else
		insert_beginning(&stacks->head_a, stacks->head_b->nb);
	remove_node(stacks->head_b);
	stacks->head_b = aux;
	if (stacks->head_b == NULL)
		stacks->tail_b = NULL;
	ft_printf("pa\n");
}

void	pb(t_stacks *stacks)
{
	t_stack	*aux;

	if (stacks->head_a == NULL)
		return ;
	if (stacks->tail_b == NULL)
		first_value(&stacks->head_b, &stacks->tail_b, stacks->head_a->nb);
	else
		insert_beginning(&stacks->head_b, stacks->head_a->nb);
	aux = stacks->head_a->next;
	remove_node(stacks->head_a);
	stacks->head_a = aux;
	ft_printf("pb\n");
}
