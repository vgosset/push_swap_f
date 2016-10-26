/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ez_begin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:50:26 by vgosset           #+#    #+#             */
/*   Updated: 2016/10/26 15:50:29 by vgosset          ###   ########.fr       */
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
		return (_SUCCESS_);
	}
	return (_ERROR_);
}

static int		choice_algo(t_pushswap *ps)
{
	int		cpt;

	cpt = 0;
	while (cpt < ps->tmpa - 1 && ps->a[cpt] < ps->a[cpt + 1])
		cpt++;
	if (cpt == ps->tmpa - 1)
		return (_ERROR_);
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
	return (_ERROR_);
}

int				easy_begin(t_pushswap *ps)
{
	int		choice;

	if (algo_reverse(ps) == _SUCCESS_ && get_fault(ps->a, ps->tmpa) == NO_FAULT)
		return (_SUCCESS_);
	choice = choice_algo(ps);
	if (choice == EASY_ROTATE)
	{
		while (rotate_basic_a(ps) == _SUCCESS_)
			;
		if (get_fault(ps->a, ps->tmpa) == NO_FAULT)
			return (_SUCCESS_);
	}
	else if (choice == HARD_ROTATE)
	{
		while (rotate_hard_a(ps) == _SUCCESS_)
			;
		if (get_fault(ps->a, ps->tmpa) == NO_FAULT)
			return (_SUCCESS_);
	}
	return (_ERROR_);
}
