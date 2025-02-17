/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:18:29 by hallfana          #+#    #+#             */
/*   Updated: 2024/11/30 15:08:47 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static t_list	*ps_get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->value < min->value))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

static void	ps_index_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = ps_get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = ps_get_next_min(stack);
	}
}

static void	ps_init_stack_a(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ps_lstnew(ft_atoi(args[i]));
		ps_lstadd_back(stack, new);
		i++;
	}
	ps_index_stack(stack);
	if (argc == 2)
		ft_free(args);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		ft_error("Error\n");
	ft_check_args(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list *));
	stack_b = (t_list **)malloc(sizeof(t_list *));
	*stack_a = NULL;
	*stack_b = NULL;
	ps_init_stack_a(stack_a, argc, argv);
	if (ps_is_sorted(stack_a))
	{
		ps_free_stack(stack_a);
		ps_free_stack(stack_b);
		return (0);
	}
	if (ps_lstsize(*stack_a) <= 5)
		ps_simple_sort(stack_a, stack_b);
	else
		ps_radix_sort(stack_a, stack_b);
	ps_free_stack(stack_a);
	ps_free_stack(stack_b);
	return (0);
}
