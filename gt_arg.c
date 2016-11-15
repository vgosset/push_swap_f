/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 14:12:28 by vgosset           #+#    #+#             */
/*   Updated: 2016/11/15 13:04:37 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int			check_intmax(char *tab)
{
	char *tmp;

	tmp = ft_itoa(ft_atoi(tab));
	if (ft_strcmp(tmp, tab) == 0)
		return (1);
	return (0);
}

static void		get_arg_2(t_checker *c, int ac, char **av)
{
	char	**lst;
	int		i;
	int		j;
	int		tmp;

	c->a = (int *)ft_memalloc(sizeof(int) * (c->len));
	c->b = (int *)ft_memalloc(sizeof(int) * (c->len));
	i = 0;
	tmp = -1;
	while (++i < ac)
	{
		lst = ft_strsplit(av[i], ' ');
		j = -1;
		while (lst[++j])
		{
			if (check_intmax(lst[j]) == 0)
			{
				ft_putstr_fd("Error\n", 2);
				_exit(0);
			}
			c->a[++tmp] = ft_atoi(lst[j]);
		}
		ft_memdel2((void ***)&lst);
	}
}

int				get_arg(t_checker *c, int ac, char **av)
{
	int		i;
	int		j;
	char	**lst;

	i = 0;
	c->len = 0;
	while (++i < ac)
	{
		lst = ft_strsplit(av[i], ' ');
		j = -1;
		while (lst[++j])
		{
			if (!ft_strisdigit(lst[j]))
				return (0);
			c->len++;
		}
		ft_memdel2((void ***)&lst);
	}
	get_arg_2(c, ac, av);
	c->tmpa = c->len;
	c->tmpb = 0;
	return (1);
}


