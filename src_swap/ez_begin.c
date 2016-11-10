/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ez_begin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:50:26 by vgosset           #+#    #+#             */
/*   Updated: 2016/11/10 12:32:29 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

static int		swap_last(t_pushswap *ps)
{
	int		min;

	min = get_min(ps->a, ps->tmpa - 2);
	if (ps->a[ps->tmpa - 1] < min && ps->a[ps->tmpa - 2] < min)
	{
		rule_rra(ps);
		rule_rra(ps);
		rule_sa(ps);
		return (1);
	}
	return (0);
}

static int		choice_algo(t_pushswap *ps)
{
	int		cpt;

	cpt = 0;
	while (cpt < ps->tmpa - 1 && ps->a[cpt] < ps->a[cpt + 1])
		cpt++;
	if (cpt == ps->tmpa - 1)
		return (0);
	cpt++;
	while (cpt < ps->tmpa - 1 && ps->a[cpt] < ps->a[cpt + 1] &&
			ps->a[cpt + 1] < ps->a[0])
		cpt++;
	if (cpt == ps->tmpa - 1)
		return (EASY_ROTATE);
	cpt++;
	while (cpt < ps->tmpa - 1 && ps->a[cpt] < ps->a[cpt + 1])
		cpt++;
	if (cpt == ps->tmpa - 1 && ps->a[cpt - 1] < ps->a[cpt])
		return (HARD_ROTATE);
	if (get_fault(ps->a, ps->tmpa) + 1 == ps->tmpa - 1)
		return (swap_last(ps));
	return (0);
}

int				easy_begin(t_pushswap *ps)
{
	int		choice;

	if (algo_reverse(ps) == 1 && get_fault(ps->a, ps->tmpa) == NO_FAULT)
		return (1);
	choice = choice_algo(ps);
	if (choice == EASY_ROTATE)
	{
		while (rotate_basic_a(ps) == 1)
			;
		if (get_fault(ps->a, ps->tmpa) == NO_FAULT)
			return (1);
	}
	else if (choice == HARD_ROTATE)
	{
		while (rotate_hard_a(ps) == 1)
			;
		if (get_fault(ps->a, ps->tmpa) == NO_FAULT)
			return (1);
	}
	return (0);
}
