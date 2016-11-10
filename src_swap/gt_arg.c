/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:09:52 by vgosset           #+#    #+#             */
/*   Updated: 2016/11/08 13:10:09 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

void	get_arg_help(t_pushswap *ps, int ac, char **av, int arg)
{
	char	**list;
	int		i;
	int		j;
	int		tmp;

	ps->a = (int *)ft_memalloc(sizeof(int) * (ps->len));
	ps->b = (int *)ft_memalloc(sizeof(int) * (ps->len));
	i = arg;
	tmp = -1;
	while (++i < ac)
	{
		list = ft_strsplit(av[i], ' ');
		j = -1;
		while (list[++j])
			ps->a[++tmp] = ft_atoi(list[j]);
		ft_memdel2((void ***)&list);
	}
	ps->tmpa = ps->len;
	ps->tmpb = 0;
}

int		get_arg(t_pushswap *ps, int ac, char **av, int arg)
{
	int		i;
	int		j;
	char	**list;

	i = arg;
	ps->len = 0;
	while (++i < ac)
	{
		list = ft_strsplit(av[i], ' ');
		j = -1;
		while (list[++j])
		{
			if (!ft_strisdigit(list[j]))
				return (0);
			ps->len++;
		}
		ft_memdel2((void ***)&list);
	}
	get_arg_help(ps, ac, av, arg);
	return (1);
}
