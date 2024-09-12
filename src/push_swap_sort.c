/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:23:07 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/09/11 21:55:47 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	finish_rotation(t_stack **stack, t_stack *top_node, char flag)
{
	while (*stack != top_node)
	{
		if (flag == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (flag == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheap)
{
	while (*a != cheap->target
		&& *b != cheap)
		rr(a, b, false);
	set_position(*a);
	set_position(*b);
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheap)
{
	while (*a != cheap->target
		&& *b != cheap)
		rrr(a, b, false);
	set_position(*a);
	set_position(*b);
}

void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = return_cheap(*b);
	if (cheap->above_median
		&& cheap->target->above_median)
		rotate_both(a, b, cheap);
	else if (!(cheap->above_median)
		&& !(cheap->target->above_median))
		reverse_rotate_both(a, b, cheap);
	finish_rotation(b, cheap, 'b');
	finish_rotation(a, cheap->target, 'a');
	pa(a, b, false);
}

