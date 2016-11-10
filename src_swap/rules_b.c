/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:47:35 by vgosset           #+#    #+#             */
/*   Updated: 2016/11/10 15:06:53 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rule_ra(t_pushswap *ps)
{
	int		tmp;

	tmp = ps->a[0];
	push_up_sort(ps->a, ps->tmpa);
	ps->a[ps->tmpa - 1] = tmp;
	if (ps->print_rules == true)
		ft_putendl("ra");
	if (ps->print_display == true)
		display(ps);
	ps->count++;
}

void	rule_rb(t_pushswap *ps)
{
	int		tmp;

	tmp = ps->b[0];
	push_up_sort(ps->b, ps->tmpb);
	ps->b[ps->tmpb - 1] = tmp;
	if (ps->print_rules == true)
		ft_putendl("rb");
	if (ps->print_display == true)
		display(ps);
	ps->count++;
}

void	rule_rra(t_pushswap *ps)
{
	int		tmp;

	tmp = ps->a[ps->tmpa - 1];
	push_back_sort(ps->a, ps->tmpa);
	ps->a[0] = tmp;
	if (ps->print_rules == true)
		ft_putendl("rra");
	if (ps->print_display == true)
		display(ps);
	ps->count++;
}

void	rule_rrb(t_pushswap *ps)
{
	int		tmp;

	tmp = ps->b[ps->tmpb - 1];
	push_back_sort(ps->b, ps->tmpb);
	ps->b[0] = tmp;
	if (ps->print_rules == true)
		ft_putendl("rrb");
	if (ps->print_display == true)
		display(ps);
	ps->count++;
}
