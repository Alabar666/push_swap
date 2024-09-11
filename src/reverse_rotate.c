/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:12:13 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/09/11 15:31:45 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	int		len;

	len = stack_len(*stack);
	if (!*stack || !stack || len == 1)
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack **a, bool flag)
{
	reverse_rotate(a);
	if (!flag)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, bool flag)
{
	reverse_rotate(b);
	if (!flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool flag)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!flag)
		write(1, "rrr\n", 4);
}
