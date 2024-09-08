/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:07:41 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/09/08 17:23:52 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*stack_new(int content)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->nbr = content;
	stack->next = NULL;
    stack->prev = NULL;
	return (stack);
}

t_stack	*stack_new_node(t_stack *node, int content)
{
	t_stack	*new_node;

	new_node = stack_new(content);
	if (!new_node)
		return (NULL);
	if (!node)
		return (new_node);
	node->next = new_node;
    new_node->prev = node;
	return (new_node);
}