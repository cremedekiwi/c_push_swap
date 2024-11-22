/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarumuga <jarumuga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:09:04 by jarumuga          #+#    #+#             */
/*   Updated: 2024/07/30 13:20:05 by jarumuga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_stacks(t_stacks *stacks)
{
	stacks->head_a = NULL;
	stacks->tail_a = NULL;
	stacks->head_b = NULL;
	stacks->tail_b = NULL;
}

void	first_value(t_stack **head, t_stack **tail, long value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		exit(2);
		return ;
	}
	new_node->nb = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	*head = new_node;
	*tail = new_node;
}

// if my stack a is empty i call first_value otherwise i insert at the end
void	populate_stack(t_stacks *stacks, long nbr)
{
	if (stacks->tail_a == NULL)
		first_value(&stacks->head_a, &stacks->tail_a, nbr);
	else
		insert_end(&stacks->tail_a, nbr);
}

/*
if my numbers are in one argv, i need to split it
*/
void	split_argv(char *arg, t_stacks *stacks, int *nb)
{
	char	**my_argv;
	int		j;

	if (!arg || !stacks || !nb)
		return ;
	my_argv = ft_split(arg, ' ');
	if (!my_argv)
		return ;
	j = 0;
	while (my_argv[j] != NULL)
	{
		if (!is_number(my_argv[j]))
			return (free_array(my_argv), ft_error());
		if (ft_atoi(my_argv[j]) > INT_MAX)
			return (free_array(my_argv), ft_error());
		j++;
	}
	j = 0;
	while (my_argv[j] != NULL)
		populate_stack(stacks, ft_atoi(my_argv[j++]));
	free_array(my_argv);
	*nb += j;
}

// if it's between "quote" i split otherwise i put numbers in stack a
int	parse_argv(int ac, char **av, t_stacks *stacks)
{
	int		i;
	int		nb;

	if (!av || !stacks)
		return (0);
	nb = 0;
	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) > INT_MAX)
			return (deallocate_stacks(stacks), ft_error(), 0);
		if (ac == 2 && ft_strchr(av[i], ' ') != NULL)
			split_argv(av[i], stacks, &nb);
		else
		{
			if (!is_number(av[i]))
				return (deallocate_stacks(stacks), ft_error(), 0);
			populate_stack(stacks, ft_atoi(av[i]));
			nb++;
		}
		i++;
	}
	return (nb);
}
