/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                    +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 13:46:22 by vgosset          #+#    #+#              */
/*   Updated: 2016/10/26 15:29:26 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int		ez_rule(t_checker *c, char *rule)
{
	if (ft_strncmp(rule, "ss", 3) == 0)
	{
		rule_sa(c);
		rule_sb(c);
	}
	else if (ft_strncmp(rule, "rrr", 4) == 0)
	{
		rule_rra(c);
		rule_rrb(c);
	}
	else if (ft_strncmp(rule, "rr", 3) == 0)
	{
		rule_ra(c);
		rule_rb(c);
	}
	else
		return (_ERROR_);
	return (_SUCCESS_);
}

int		select_rule(t_checker *c, char *rule)
{
	if (ft_strncmp(rule, "sa", 3) == 0)
		rule_sa(c);
	else if (ft_strncmp(rule, "sb", 3) == 0)
		rule_sb(c);
	else if (ft_strncmp(rule, "pa", 3) == 0)
		rule_pa(c);
	else if (ft_strncmp(rule, "pb", 3) == 0)
		rule_pb(c);
	else if (ft_strncmp(rule, "ra", 3) == 0)
		rule_ra(c);
	else if (ft_strncmp(rule, "rb", 3) == 0)
		rule_rb(c);
	else if (ft_strncmp(rule, "rra", 4) == 0)
		rule_rra(c);
	else if (ft_strncmp(rule, "rrb", 4) == 0)
		rule_rrb(c);
	else if (ez_rule(c, rule) == _SUCCESS_)
		;
	else
		return (_ERROR_);
	return (_SUCCESS_);
}
