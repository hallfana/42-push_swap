/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:24:43 by hallfana          #+#    #+#             */
/*   Updated: 2024/11/30 15:08:30 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_print_list(t_list *head)
{
	t_list	*t;

	t = head;
	while (t != NULL)
	{
		ft_putnbr_fd(t->value, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(t->index, 1);
		ft_putendl_fd("", 1);
		t = t->next;
	}
}
