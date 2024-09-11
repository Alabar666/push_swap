/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:00:09 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/09/11 20:26:45 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


void	set_position(t_stack *stack)
{
	int	i;
	int	mid;

	if (!stack)
		return ;
	mid = stack_len(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->idx = i;
		if (i <= mid)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void    set_target(t_stack *a, t_stack *b)
{
    t_stack *current_a;
    t_stack *target;
    long    best;
    
    while(b)
    {
        best = LONG_MAX;
        current_a = a;
        while(current_a)
        {
            if(current_a->nbr > b->nbr && current_a->nbr < best)
            {
                best = current_a->nbr;
                target= current_a;
            }
            current_a = current_a->next;
        }
        if(LONG_MAX == best)
            b->target = find_small(a);
        else
            b->target = target;
        b = b->next;        
    }
}

void    set_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
    
    while(b)
    {
        b->pcost = b->idx;
        if(!(b->above_median))
            b->pcost = len_b - (b->idx);
        if(b->target->above_median)
            b->pcost += b->target->idx;
        else
            b->pcost += len_a - (b->target->idx);
        b = b->next;
    }
}
void    set_small(t_stack *b)
{
    long    best;
    t_stack *node;

    if(!b)
        return;
    best =  LONG_MAX;
    while(b)
    {
        if(b->pcost < best)
        {
            best = b->pcost;
            node = b;
        }
        b = b->next;
    }
    node->cheap = true;
}

void    check_nodes(t_stack *a, t_stack *b)
{
    set_position(a);
    set_position(b);
    set_target(a, b);
    set_cost(a, b);
    set_small(b);
}