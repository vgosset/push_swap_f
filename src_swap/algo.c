/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 12:35:36 by vgosset           #+#    #+#             */
/*   Updated: 2016/11/10 15:05:42 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		insertion_algo(t_pushswap *ps)
{
	int		i;

	while (ps->tmpb)
	{
		i = get_index(ps->b, ps->tmpb, get_max(ps->b, ps->tmpb));
		if (i < ps->tmpb / 2)
		{
			while (i--)
				rule_rb(ps);
		}
		else
		{
			while (++i <= ps->tmpb)
				rule_rrb(ps);
		}
		rule_pa(ps);
	}
}

int				algo_reverse(t_pushswap *ps)
{
	int		cpt;

	cpt = 0;
	while (cpt < ps->tmpa - 1)
	{
		if (ps->a[cpt] < ps->a[cpt + 1])
			return (_ERROR_);
		cpt++;
	}
	if (cpt == 2)
	{
		rule_sa(ps);
		rule_rra(ps);
		return (_SUCCESS_);
	}
	while (ps->tmpa > 1)
	{
		rule_rra(ps);
		rule_pb(ps);
	}
	while (ps->tmpb)
		rule_pa(ps);
	return (_SUCCESS_);
}

static void		segment_sort(t_pushswap *ps, int stage)
{
	int		cpt;
	int		len;

	cpt = -1;
	len = ps->tmpa;
	while (get_min(ps->a, ps->tmpa) < stage)
	{
		while (ps->a[0] >= stage)
			rule_ra(ps);
		rule_pb(ps);
	}
}

static int		segment_len(int len)
{
	if (len >= 4000)
		return (35);
	if (len >= 2000)
		return (25);
	if (len >= 1000)
		return (20);
	if (len >= 500)
		return (14);
	if (len >= 400)
		return (12);
	if (len >= 300)
		return (10);
	if (len >= 200)
		return (8);
	if (len >= 100)
		return (5);
	if (len >= 25)
		return (4);
	return (2);
}

void			push_swap(t_pushswap *ps)
{
	int		*sort;
	int		cpt;
	int		stage;
	int		seg;

	if (ps->print_display == true || ps->final_display == true)
		display(ps);
	if (easy_begin(ps) == _SUCCESS_)
		return ;
	sort = ft_intdup(ps->a, ps->len);
	sort_sample_list(sort, 0, ps->len - 1);
	cpt = segment_len(ps->len);
	stage = ps->len / cpt;
	seg = stage;
	while (cpt-- > 1)
	{
		segment_sort(ps, sort[stage]);
		stage += seg;
	}
	while (ps->tmpa)
		rule_pb(ps);
	insertion_algo(ps);
	ft_memdel((void **)&sort);
}
