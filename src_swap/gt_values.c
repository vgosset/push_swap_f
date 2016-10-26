/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gt_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 10:34:54 by vgosset           #+#    #+#             */
/*   Updated: 2016/10/26 15:48:43 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_fault(int *p, int len)
{
	int		i;

	i = 0;
	while (++i < len)
	{
		if (p[i - 1] > p[i])
			return (i);
	}
	return (0);
}

int		get_max(int *p, int len)
{
	int		max;

	max = -2147483648;
	while (len--)
	{
		if (max < p[len])
			max = p[len];
	}
	return (max);
}

int		get_min(int *p, int len)
{
	int		min;

	min = 2147483647;
	while (len--)
	{
		if (min > p[len])
			min = p[len];
	}
	return (min);
}

int		get_index(int *p, int len, int present)
{
	int		i;

	i = -1;
	while (++i < len)
	{
		if (p[i] == present)
			break ;
	}
	return (i);
}
