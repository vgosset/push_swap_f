/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:46:43 by vgosset           #+#    #+#             */
/*   Updated: 2016/11/10 15:06:24 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		check_duplicate(t_pushswap *ps)
{
	int		i;
	int		j;

	i = -1;
	while (++i < ps->len)
	{
		j = -1;
		while (++j < ps->len)
		{
			if (j != i)
			{
				if (ps->a[i] == ps->a[j])
					return (_ERROR_);
			}
		}
	}
	return (_SUCCESS_);
}

static int		check_basic_sort(t_pushswap *ps)
{
	int		i;

	i = ps->len - 1;
	while (--i >= 0)
	{
		if (ps->a[i] > ps->a[i + 1])
			return (_ERROR_);
	}
	return (_SUCCESS_);
}

static int		get_mode(t_pushswap *ps, int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-v"))
			ps->print_display = true;
		else if (!ft_strcmp(av[i], "-e"))
			ps->final_display = true;
		else if (!ft_strcmp(av[i], "-c"))
			ps->count_rules = true;
		else if (!ft_strcmp(av[i], "-b"))
			ps->print_rules = false;
		else if (!ft_strcmp(av[i], "?") || !ft_strcmp(av[i], "-h") ||
				!ft_strcmp(av[i], "--help") || !ft_strcmp(av[i], "-help"))
			return (-1);
		else
			return (i - 1);
		i++;
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_pushswap		ps;

	ps.count = 0;
	ps.count_rules = false;
	ps.print_rules = true;
	ps.final_display = false;
	ps.print_display = false;
	if ((ps.arg = get_mode(&ps, argc, argv)) == -1)
		ft_putstr("help:\n-v : display all piles\n-e : display final pile\n\
-c : count total rules\n-b : hide rules\n");
	else if (!get_arg(&ps, argc, argv, ps.arg))
		ft_putstr_fd("Error\n", 2);
	else if (!check_duplicate(&ps))
		ft_putstr_fd("Error\n", 2);
	else if (!check_basic_sort(&ps))
	{
		push_swap(&ps);
		if (ps.final_display == true)
			display(&ps);
		if (ps.count_rules == true)
			ft_printf("number rules : %d\n", ps.count);
	}
	ft_memdel((void **)&ps.a);
	ft_memdel((void **)&ps.b);
	return (0);
}
