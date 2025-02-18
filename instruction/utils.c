/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:16:15 by hallfana          #+#    #+#             */
/*   Updated: 2024/11/30 15:09:22 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ps_swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		tmp_val;
	int		tmp_index;

	if (ps_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		ft_error("Error\n");
	tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	ps_push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (ps_lstsize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}

int	ps_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ps_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ps_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ps_reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ps_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ps_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

void	ps_free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

long	ft_atol(char *ptr)
{
	long long	i;
	long long	sign;
	long long	r;

	i = 0;
	sign = 1;
	r = 0;
	while (ptr[i] && ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == ' '))
		i++;
	if (ptr[i] && (ptr[i] == '-' || ptr[i] == '+'))
	{
		if (ptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ptr[i] && (ptr[i] >= '0' && ptr[i] <= '9'))
	{
		r = r * 10 + ptr[i] - '0';
		i++;
	}
	return ((long)(r * sign));
}
