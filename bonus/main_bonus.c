/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:31:27 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/09/11 17:35:01 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (av == NULL)
			return (1);
		stack_init(&a, av, true);
	}
	else
	{
		stack_init(&a, av + 1, false);
	}
	print_stacks(a, NULL);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		fd_command(&a, &b, line);
		print_stacks(a, b);
		free(line);
	}
	validate(a, b);
	free_stack(&a);
	free_stack(&b);
	free(line);
	return (0);
}
