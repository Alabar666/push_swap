/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:33:02 by hluiz-ma          #+#    #+#             */
/*   Updated: 2024/09/11 17:41:28 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	fd_command(t_stack **a, t_stack **b, char *command)
{
	if (!ft_strncmp(command, "pa\n", 3))
		pa(a, b, true);
	else if (!ft_strncmp(command, "pb\n", 3))
		pb(b, a, true);
	else if (!ft_strncmp(command, "sa\n", 3))
		sa(a, true);
	else if (!ft_strncmp(command, "sb\n", 3))
		sb(b, true);
	else if (!ft_strncmp(command, "ss\n", 3))
		ss(a, b, true);
	else if (!ft_strncmp(command, "ra\n", 3))
		ra(a, true);
	else if (!ft_strncmp(command, "rb\n", 3))
		rb(b, true);
	else if (!ft_strncmp(command, "rr\n", 3))
		rr(a, b, true);
	else if (!ft_strncmp(command, "rra\n", 4))
		rra(a, true);
	else if (!ft_strncmp(command, "rrb\n", 4))
		rrb(b, true);
	else if (!ft_strncmp(command, "rrr\n", 4))
		rrr(a, b, true);
	else
		write(1, "Error\n", 7);
}

void	validate(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && b == 0)
	{
		write(1, GREEN, 7);
		write(1, "OK\n", 3);
		write(1, RESET, 4);
	}
	else
	{
		write(1, RED, 7);
		write(1, "KO\n", 3);
		write(1, RESET, 4);
	}
}
