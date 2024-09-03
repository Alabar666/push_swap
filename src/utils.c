/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:31:27 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/09/03 21:08:21 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ft_atol(const char *str)
{
	int	i;
	int	sing;
	long	num;

	i = 0;
	sing = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sing = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return (num * sing);
}

void	print_stacks(t_stack *stack1, t_stack *stack2)
{
	t_stack	*current1;
	t_stack	*current2;

	//current1 = stack_first(stack1);
	//current2 = stack_first(stack2);
	ft_printf("A ----- B\n");
	while (current1 || current2)
	{
		if (current1)
		{
			ft_printf("%i\t", current1->nbr);
			current1 = current1->next;
		}
		else
			ft_printf("\t");
		if (current2)
		{
			ft_printf("%i\n", current2->nbr);
			current2 = current2->next;
		}
		else
			ft_printf("\n");
	}
}