/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 16:08:14 by vgosset           #+#    #+#             */
/*   Updated: 2016/10/26 15:02:38 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/checker.h"

static int		get_rule(t_checker *c)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (select_rule(c, line) == _ERROR_)
			return (_ERROR_);
	}
	return (_SUCCESS_);
}

static int		check_dbl(t_checker *c)
{
	int		i;
	int		j;

	i = -1;
	while (++i < c->len)
	{
		j = -1;
		while (++j < c->len)
		{
			if (j != i)
			{
				if (c->a[i] == c->a[j])
					return (_ERROR_);
			}
		}
	}
	return (_SUCCESS_);
}

static int		check_order(t_checker *c)
{
	int		i;

	if (c->tmpb != 0)
		return (_ERROR_);
	i = c->len - 1;
	while (--i >= 0)
	{
		if (c->a[i] > c->a[i + 1])
			return (_ERROR_);
	}
	return (_SUCCESS_);
}

int				main(int argc, char **argv)
{
	t_checker	c;

	if (argc == 1)
		return (0);
	if (!get_arg(&c, argc, argv))
		ft_putstr_fd("Error\n", 2);
	else if (!check_dbl(&c))
		ft_putstr_fd("Error\n", 2);
	else if (!get_rule(&c))
		ft_putstr_fd("Error\n", 2);
	else if (!check_order(&c))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	c.begin = ft_lstline_del(c.begin);
	ft_memdel((void **)&c.a);
	ft_memdel((void **)&c.b);
	return (0);
}
