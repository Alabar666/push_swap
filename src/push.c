/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugodev <hugodev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:03:16 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/09/09 13:09:35 by hugodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void push(t_stack **dest, t_stack **src)
{
    t_stack *node;
    
    if(!*src)
        return;
    node = *src;
    *src= (*src)->next;
    if(*src)
        (*src)->prev = NULL;
    node->prev = NULL;
    if(!*dest)
    {
        *dest = node;
        node->next = NULL;
    }
    else
    {
        node->next = *dest;
        node->next->prev = node;
        *dest = node;   
    }
}

void pa(t_stack **a, t_stack **b)
{	
    push(a, b);
	write(1, "pa\n", 3);    
}

void pb(t_stack **b, t_stack **a)
{	
    push(b, a);
	write(1, "pb\n", 3);    
}