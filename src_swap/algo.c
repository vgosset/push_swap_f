/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:48:58 by vgosset           #+#    #+#             */
/*   Updated: 2016/11/03 12:38:01 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

static void		insertion_algo(t_pushswap *ps)
{
	int		index;

	while (ps->tmpb)
	{
		index = get_index(ps->b, ps->tmpb, get_max(ps->b, ps->tmpb));
		if (index < ps->tmpb / 2)
		{
			while (index--)
				rule_rb(ps);
		}
		else
		{
			while (++index <= ps->tmpb)
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
			return (0);
		cpt++;
	}
	if (cpt == 2)
	{
		rule_sa(ps);
		rule_rra(ps);
		return (1);
	}
	while (ps->tmpa > 1)
	{
		rule_rra(ps);
		rule_pb(ps);
	}
	while (ps->tmpb)
		rule_pa(ps);
	return (1);
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
	int		*sorted;
	int		cpt;
	int		stage;
	int		segment;

	if (ps->print_display == true || ps->final_display == true)
		display(ps);
	if (easy_begin(ps) == 1)
		return ;
	sorted = ft_intdup(ps->a, ps->len);
	sort_sample_list(sorted, 0, ps->len - 1);
	cpt = segment_len(ps->len);
	stage = ps->len / cpt;
	segment = stage;
	while (cpt-- > 1)
	{
		segment_sort(ps, sorted[stage]);
		stage += segment;
	}
	while (ps->tmpa)
		rule_pb(ps);
	insertion_algo(ps);
	ft_memdel((void **)&sorted);
}
