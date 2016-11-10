/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gt_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:45:47 by vgosset           #+#    #+#             */
/*   Updated: 2016/11/10 15:06:00 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_arg_help(t_pushswap *ps, int ac, char **av, int arg)
{
	char	**lst;
	int		i;
	int		j;
	int		tmp;

	ps->a = (int *)ft_memalloc(sizeof(int) * (ps->len));
	ps->b = (int *)ft_memalloc(sizeof(int) * (ps->len));
	i = arg;
	tmp = -1;
	while (++i < ac)
	{
		lst = ft_strsplit(av[i], ' ');
		j = -1;
		while (lst[++j])
			ps->a[++tmp] = ft_atoi(lst[j]);
		ft_memdel2((void ***)&lst);
	}
	ps->tmpa = ps->len;
	ps->tmpb = 0;
}

int		get_arg(t_pushswap *ps, int ac, char **av, int arg)
{
	int		i;
	int		j;
	char	**lst;

	i = arg;
	ps->len = 0;
	while (++i < ac)
	{
		lst = ft_strsplit(av[i], ' ');
		j = -1;
		while (lst[++j])
		{
			if (!ft_strisdigit(lst[j]))
				return (_ERROR_);
			ps->len++;
		}
		ft_memdel2((void ***)&lst);
	}
	get_arg_help(ps, ac, av, arg);
	return (_SUCCESS_);
}
