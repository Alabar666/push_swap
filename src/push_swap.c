/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugodev <hugodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:56:16 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/09/14 11:50:33 by hugodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_above(t_stack *stack, int target)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->nbr < target)
			count++;
		stack = stack->next;
	}
	return (count);
}

t_stack	*find_above(t_stack *stack, int target)
{
	t_stack	*result;

	result = stack;
	while (result->next)
	{
		if (result->nbr < target)
		{
			return (result);
		}
		result = result->next;
	}
	return (stack);
}

void	check_before_push(t_stack **a, t_stack **b, int target)
{
	int	len;
	int	pb_n;

	pb_n = check_above(*a, target);
	len = stack_len(*a);
	while (len > 3 && (pb_n > 0) && !is_sorted(*a))
	{
		set_position(*a);
		finish_rotation((a), find_above(*a, target), 'a');
		if ((*a)->nbr < target)
		{
			pb(b, a, false);
			len--;
			pb_n--;
		}
		else
			ra(a, false);
	}
}

void	move_b(t_stack **a, t_stack **b)
{
	int		i;
	long	min;
	long	max;
	int		target;

	i = stack_len(*a);
	while (i > 3 && !is_sorted(*a))
	{
		i = stack_len(*a);
		min = nbr_min(*a);
		max = nbr_max(*a);
		target = min + ((max - min) / 2);
		check_before_push(a, b, target);
	}
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*small;

	if (stack_len(*a) == 2)
		sa(a, false);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else
		sort_all(a, b);
	small = find_small(*a);
	while ((*a) != small)
	{
		if (small->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}
