/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 15:05:27 by vgosset           #+#    #+#             */
/*   Updated: 2016/10/26 15:42:37 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rule_ss(t_pushswap *ps)
{
	rule_sa(ps);
	rule_sb(ps);
}

void	rule_rr(t_pushswap *ps)
{
	rule_ra(ps);
	rule_rb(ps);
}

void	rule_rrr(t_pushswap *ps)
{
	rule_rra(ps);
	rule_rrb(ps);
}
