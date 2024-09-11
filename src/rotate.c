/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:12:19 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/09/11 14:19:43 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*last_node;
	int		len;

	len = stack_len(*stack);
	if (!stack || !*stack || len == 1)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack **a, bool flag)
{
	rotate(a);
	if (!flag)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, bool flag)
{
	rotate(b);
	if (!flag)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, bool flag)
{
	rotate(a);
	rotate(b);
	if (!flag)
		write(1, "rr\n", 3);
}
