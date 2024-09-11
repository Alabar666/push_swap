/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:12:30 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/09/11 18:49:13 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*find_last_node(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int	stack_len(t_stack *stack)
{
	int		len;
	t_stack	*temp;

	temp = stack;
	len = 0;
	while (temp && temp->prev)
	{
		temp = temp->prev;
	}
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

t_stack	*find_small(t_stack *stack)
{
	long	small;
	t_stack	*small_node;

	if (!stack)
		return (NULL);
	small = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < small)
		{
			small = stack->nbr;
			small_node = stack;
		}
		stack = stack->next;
	}
	return (small_node);
}

t_stack	*return_cheap(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheap)
			return (stack);
		stack = stack->next;
	}
	return (0);
}


