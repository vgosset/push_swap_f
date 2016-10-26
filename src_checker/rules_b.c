/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 14:37:03 by vgosset           #+#    #+#             */
/*   Updated: 2016/10/26 15:07:30 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/checker.h"

void	rule_ra(t_checker *c)
{
	int		tmp;

	tmp = c->a[0];
	push_up_sort(c->a, c->tmpa);
	c->a[c->tmpa - 1] = tmp;
}

void	rule_rb(t_checker *c)
{
	int		tmp;

	tmp = c->b[0];
	push_up_sort(c->b, c->tmpb);
	c->b[c->tmpb - 1] = tmp;
}

void	rule_rra(t_checker *c)
{
	int		tmp;

	tmp = c->a[c->tmpa - 1];
	push_back_sort(c->a, c->tmpa);
	c->a[0] = tmp;
}

void	rule_rrb(t_checker *c)
{
	int		tmp;

	tmp = c->b[c->tmpb - 1];
	push_back_sort(c->b, c->tmpb);
	c->b[0] = tmp;
}
