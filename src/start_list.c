/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:07:41 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/08/28 20:32:45 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*t_stack_new(int content)
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