/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:54:26 by hallfana          #+#    #+#             */
/*   Updated: 2024/11/30 15:19:05 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ps_sort_3_sub(t_list **phead, int *pmin, int *pnext_min,
	t_list **stack_a)
{
	if ((*phead)->index == *pmin && (*phead)->next->index != *pnext_min)
	{
		ps_ra(stack_a);
		ps_sa(stack_a);
		ps_rra(stack_a);
	}
	else if ((*phead)->index == *pnext_min)
	{
		if ((*phead)->next->index == *pmin)
			ps_sa(stack_a);
		else
			ps_rra(stack_a);
	}
	else
	{
		if ((*phead)->next->index == *pmin)
			ps_ra(stack_a);
		else
		{
			ps_sa(stack_a);
			ps_rra(stack_a);
		}
	}
}

static void	ps_sort_3(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = ps_get_min_simple(stack_a, -1);
	next_min = ps_get_min_simple(stack_a, min);
	if (ps_is_sorted(stack_a))
		return ;
	ps_sort_3_sub(&head, &min, &next_min, stack_a);
}

static void	ps_sort_4(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (ps_is_sorted(stack_a))
		return ;
	distance = ps_get_distance(stack_a, ps_get_min_simple(stack_a, -1));
	if (distance == 1)
		ps_ra(stack_a);
	else if (distance == 2)
	{
		ps_ra(stack_a);
		ps_ra(stack_a);
	}
	else if (distance == 3)
		ps_rra(stack_a);
	if (ps_is_sorted(stack_a))
		return ;
	ps_pb(stack_a, stack_b);
	ps_sort_3(stack_a);
	ps_pa(stack_a, stack_b);
}

void	ps_sort_5(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = ps_get_distance(stack_a, ps_get_min_simple(stack_a, -1));
	if (distance == 1)
		ps_ra(stack_a);
	else if (distance == 2)
	{
		ps_ra(stack_a);
		ps_ra(stack_a);
	}
	else if (distance == 3)
	{
		ps_rra(stack_a);
		ps_rra(stack_a);
	}
	else if (distance == 4)
		ps_rra(stack_a);
	if (ps_is_sorted(stack_a))
		return ;
	ps_pb(stack_a, stack_b);
	ps_sort_4(stack_a, stack_b);
	ps_pa(stack_a, stack_b);
}

void	ps_simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (ps_is_sorted(stack_a) || ps_lstsize(*stack_a) == 0
		|| ps_lstsize(*stack_a) == 1)
		return ;
	size = ps_lstsize(*stack_a);
	if (size == 2)
		ps_sa(stack_a);
	else if (size == 3)
		ps_sort_3(stack_a);
	else if (size == 4)
		ps_sort_4(stack_a, stack_b);
	else if (size == 5)
		ps_sort_5(stack_a, stack_b);
}
