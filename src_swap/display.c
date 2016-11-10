/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 15:44:25 by vgosset           #+#    #+#             */
/*   Updated: 2016/11/10 15:05:47 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	display(t_pushswap *ps)
{
	int		i;

	i = -1;
	ft_putendl("Pile A");
	while (++i < ps->tmpa)
		ft_printf("->%d", ps->a[i]);
	i = -1;
	ft_putendl("\nPile B");
	while (++i < ps->tmpb)
		ft_printf("->%d", ps->b[i]);
	if (ps->tmpb > 0)
		ft_putchar('\n');
	ft_putchar('\n');
}
