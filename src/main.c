/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:31:27 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/09/15 16:32:35 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	init_stacks(int ac, char **av, t_stack **a, char ***split_av)
{
	*a = NULL;
	*split_av = NULL;
	if (ac < 2)
		return (1);
	if ((ac == 2 && !av[1][0]))
	{
		ft_printf("Error\n");
		return (1);
	}
	if (ac == 2)
	{
		*split_av = ft_split(av[1], ' ');
		if (!*split_av || is_empty_split(*split_av))
		{
			ft_printf("Error\n");
			free_av(*split_av);
			return (1);
		}
		stack_init(a, *split_av, true);
	}
	else
	{
		stack_init(a, av + 1, false);
	}
	return (0);
}

int	push_swap_sort(int ac, char **split_av, t_stack *a)
{
	t_stack	*b;

	b = NULL;
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			push_swap(&a, &b);
	}
	if (ac == 2 && split_av)
	{
		free_av(split_av);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	char	**split_av;

	if (init_stacks(ac, av, &a, &split_av))
		return (1);
	return (push_swap_sort(ac, split_av, a));
}
