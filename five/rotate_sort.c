/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:47:00 by vgosset           #+#    #+#             */
/*   Updated: 2016/11/19 17:34:21 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				rotate_basic_a(t_pushswap *ps)
{
	int		i;
	int		end;

	if (ps->tmpa < 2)
		return (_ERROR_);
	i = -1;
	end = ps->a[ps->tmpa - 1];
	if (ps->a[0] > end && end > ps->a[1])
	{
		rule_ra(ps);
		return (_SUCCESS_);
	}
	else if (ps->a[0] > end)
	{
		rule_rra(ps);
		return (_SUCCESS_);
	}
	return (_ERROR_);
}

static void		rotate_hard_help(t_pushswap *ps, int i, int tmp, int tmp2)
{
	int		good_f;

	good_f = 0;
	while (ps->a[tmp - 1] < ps->a[tmp])
	{
		good_f++;
		tmp--;
	}
	tmp2 = ps->tmpa;
	tmp = (tmp2 - i) + good_f;
	while (tmp--)
		rule_rra(ps);
	if (get_fault(ps->a, ps->tmpa) == NO_FAULT)
		return ;
	tmp = good_f + 1;
	if (tmp == 1 && (tmp2 - i) - 1 <= 0)
		return ;
	while (tmp--)
		rule_pb(ps);
	tmp = (tmp2 - i) - 1;
	while (tmp--)
		rule_ra(ps);
	tmp = good_f + 1;
	while (tmp--)
		rule_pa(ps);
}

int				rotate_hard_a(t_pushswap *ps)
{
	int		i;
	int		factor_good;

	i = ps->tmpa;
	factor_good = 0;
	while (--i >= ps->tmpa / 2)
	{
		if (ps->a[i] < ps->a[0])
		{
			rotate_hard_help(ps, i, i, ps->tmpa);
			return (_SUCCESS_);
		}
	}
	return (_ERROR_);
}

void			five_rotate(t_pushswap *ps)
{
	int i;

	i = 0;
	rule_pb(ps);
	rule_pb(ps);
	three_rotate(ps);
	while (i != 1)
	{
		if (ps->b[i] < ps->a[2])
		{
			rule_pa(ps);
			rule_ra(ps);
		}
		else if (ps->b[i] > ps->a[2] && ps->b[i] < ps->a[1])
		{
			rule_pa(ps);
			rule_rra(ps);
			rule_sa(ps);
			rule_ra(ps);
			rule_ra(ps);
		}
		else if (ps->b[i] > ps->a[1] && ps->b[i] < ps->a[0])
		{
			rule_pa(ps);
			rule_sa(ps);
		}
		i++;
	}
}

void			three_rotate(t_pushswap *ps)
{
	if (ps->a[2] > ps->a[1] && ps->a[1] < ps->a[0])
		return ;
	else if (ps->a[2] < ps->a[1] && ps->a[1] > ps->a[0] && ps->a[0] < ps->a[2])
		rule_sa(ps);
	else if (ps->a[2] > ps->a[1] && ps->a[1] < ps->a[0] && ps->a[2] < ps->a[0])
	{
		rule_rra(ps);
		rule_sa(ps);
	}
	else if (ps->a[2] > ps->a[1] && ps->a[1] > ps->a[0] && ps->a[2] > ps->a[0])
		rule_ra(ps);
	else if (ps->a[2] > ps->a[1] && ps->a[1] < ps->a[0] && ps->a[2] > ps->a[0])
		rule_rra(ps);
	else if (ps->a[2] > ps->a[1] && ps->a[1] > ps->a[0])
	{
		rule_ra(ps);
		rule_ra(ps);
	}
}
