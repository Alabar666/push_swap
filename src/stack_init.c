/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:19:45 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/09/11 20:26:54 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_init(t_stack **a, char **av, bool split)
{
	long	nbr;
	int		i;
	t_stack	*last;

	last = NULL;
	i = -1;
	while (av[++i])
	{
		if (error_syntax(av[i]))
			ft_error(a, NULL, av, split);
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_error(a, NULL, av, split);
		if (error_nbr_repet(*a, (int)nbr))
			ft_error(a, NULL, av, split);
		if (*a == NULL)
		{
			*a = stack_new((int)nbr);
			last = *a;
		}
		else
		{
			last = stack_new_node(last, (int)nbr);
		}
	}
}
