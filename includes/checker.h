/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 17:52:21 by vgosset           #+#    #+#             */
/*   Updated: 2016/10/26 14:43:30 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <unistd.h>
# include "get_next_line.h"

typedef struct	s_checker
{
	int			*a;
	int			*b;
	int			tmpa;
	int			tmpb;
	int			len;
	t_lstline	*begin;
}				t_checker;

int				select_rule(t_checker *c, char *rule);
void			rule_sa(t_checker *c);
void			rule_sb(t_checker *c);
int				get_arg(t_checker *c, int ac, char **av);
int				make_rules(t_checker *c);
void			push_up_sort(int *t, int len);
void			push_back_sort(int *t, int len);
void			rule_pa(t_checker *c);
void			rule_pb(t_checker *c);
void			rule_ra(t_checker *c);
void			rule_rb(t_checker *c);
void			rule_rra(t_checker *c);
void			rule_rrb(t_checker *c);

#endif
