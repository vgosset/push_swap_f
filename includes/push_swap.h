/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 15:15:23 by vgosset           #+#    #+#             */
/*   Updated: 2016/11/03 12:27:54 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

# include "../libft/includes/libft.h"

# define NO_FAULT		0
# define EASY_ROTATE	1
# define HARD_ROTATE	2

typedef struct	s_pushswap
{
	int		*a;
	int		*b;
	int		tmpa;
	int		tmpb;
	int		len;
	int		count;
	int		arg;
	t_bool	count_rules;
	t_bool	print_rules;
	t_bool	final_display;
	t_bool	print_display;
}				t_pushswap;

int				get_arg(t_pushswap *ps, int ac, char **av, int arg);
int				algo_reverse(t_pushswap *ps);
int				easy_begin(t_pushswap *ps);
int				get_fault(int *p, int len);
int				get_max(int *p, int len);
int				get_min(int *p, int len);
int				get_index(int *p, int len, int present);
int				rotate_basic_a(t_pushswap *ps);
int				rotate_hard_a(t_pushswap *ps);

void			rule_sa(t_pushswap *ps);
void			rule_sb(t_pushswap *ps);
void			push_swap(t_pushswap *ps);
void			rule_pa(t_pushswap *ps);
void			rule_pb(t_pushswap *ps);
void			rule_ra(t_pushswap *ps);
void			rule_rb(t_pushswap *ps);
void			rule_rra(t_pushswap *ps);
void			rule_rrb(t_pushswap *ps);
void			rule_ss(t_pushswap *ps);
void			rule_rr(t_pushswap *ps);
void			rule_rrr(t_pushswap *ps);
void			push_up_sort(int *t, int len);
void			sort_sample_list(int *list, int beg, int end);
void			push_back_sort(int *t, int len);
void			display(t_pushswap *ps);

#endif
