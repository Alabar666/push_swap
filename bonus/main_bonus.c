/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:31:27 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/09/15 17:55:40 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	init_stacks_bonus(int ac, char **av, t_stack **a, char ***split_av)
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

void	process_commands(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		fd_command(a, b, line);
		free(line);
	}
	validate(*a, *b);
	free_stack(a);
	free_stack(b);
	free(line);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_av;

	b = NULL;
	if (init_stacks_bonus(ac, av, &a, &split_av))
		return (1);
	process_commands(&a, &b);
	if (ac == 2 && split_av)
	{
		free_av(split_av);
	}
	return (0);
}
