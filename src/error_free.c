/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:25:11 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/09/15 16:21:38 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	error_syntax(char *str_nbr)
{
	int	i;

	if (!(*str_nbr == '+' || *str_nbr == '-' || (*str_nbr >= '0'
				&& *str_nbr <= '9')))
		return (1);
	if ((*str_nbr == '+' || *str_nbr == '-') && !(str_nbr[1] >= '0'
			&& str_nbr[1] <= '9'))
		return (1);
	i = -1;
	while (str_nbr[++i])
	{
		if (!(str_nbr[i] >= '0' && str_nbr[i] <= '9'))
			return (1);
	}
	return (0);
}

void	free_av(char **av)
{
	int	i;

	if (!av)
		return ;
	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
}

int	error_nbr_repet(t_stack *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	ft_error(t_stack **a, t_stack **b, char **av, bool split)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (split)
		free_av(av);
	write(2, "Error\n", 6);
	exit(1);
}
