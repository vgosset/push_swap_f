/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 16:10:51 by vgosset           #+#    #+#             */
/*   Updated: 2016/11/10 15:04:43 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	rule_sa(t_checker *c)
{
	if (c->tmpa < 2)
		return ;
	ft_swap(&c->a[0], &c->a[1]);
}

void	rule_sb(t_checker *c)
{
	if (c->tmpb < 2)
		return ;
	ft_swap(&c->b[0], &c->b[1]);
}

void	rule_pa(t_checker *c)
{
	int		tmp;

	if (c->tmpb < 1)
		return ;
	tmp = c->b[0];
	push_up_sort(c->b, c->tmpb--);
	if (c->tmpa > 0)
		push_back_sort(c->a, ++c->tmpa);
	else
		c->tmpa++;
	c->a[0] = tmp;
}

void	rule_pb(t_checker *c)
{
	int		tmp;

	if (c->tmpa < 1)
		return ;
	tmp = c->a[0];
	push_up_sort(c->a, c->tmpa--);
	if (c->tmpb > 0)
		push_back_sort(c->b, ++c->tmpb);
	else
		c->tmpb++;
	c->b[0] = tmp;
}
