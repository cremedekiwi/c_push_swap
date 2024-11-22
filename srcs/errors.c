/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:47:57 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/26 16:15:50 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_number(const char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_duplicate(t_stacks *stacks)
{
	t_stack	*curr;
	t_stack	*tmp;

	curr = stacks->head_a;
	while (curr)
	{
		tmp = curr->next;
		while (tmp)
		{
			if (curr->nb == tmp->nb)
				return (1);
			tmp = tmp->next;
		}
		curr = curr->next;
	}
	return (0);
}

int	is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}
