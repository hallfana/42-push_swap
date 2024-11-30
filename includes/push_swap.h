/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hallfana <hallfana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:58:36 by samberna          #+#    #+#             */
/*   Updated: 2024/11/30 15:01:08 by hallfana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "unistd.h"
# include "stdlib.h"
# include "libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

// utils
void	ft_error(char *msg);
void	ft_check_args(int argc, char **argv);
void	ft_free(char **str);
int		ps_get_distance(t_list **stack, int index);
int		ps_is_sorted(t_list **stack);
void	ps_free_stack(t_list **stack);

// list utils
t_list	*ps_lstnew(int value);
t_list	*ps_lstlast(t_list *head);
void	ps_lstadd_front(t_list **stack, t_list *new);
void	ps_lstadd_back(t_list **stack, t_list *new);
void	ps_printList(t_list *head);
int		ps_lstsize(t_list *head);

// push_swap func
int	ps_pa(t_list **stack_a, t_list **stack_b);
int	ps_pb(t_list **stack_a, t_list **stack_b);
int	ps_sa(t_list **stack_a);
int	ps_sb(t_list **stack_b);
int	ps_ss(t_list **stack_a, t_list **stack_b);
int	ps_ra(t_list **stack_a);
int	ps_rb(t_list **stack_b);
int	ps_rr(t_list **stack_a, t_list **stack_b);
int	ps_rra(t_list **stack_a);
int	ps_rrb(t_list **stack_b);
int	ps_rrr(t_list **stack_a, t_list **stack_b);
int	ps_push(t_list **stack_a, t_list **stack_b);
int	ps_swap(t_list **stack);
int	ps_rotate(t_list **stack);
int	ps_reverse_rotate(t_list **stack);

// algo
void	ps_simple_sort(t_list **stack_a, t_list **stack_b);
void	ps_radix_sort(t_list **stack_a, t_list **stack_b);

#endif