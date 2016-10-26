/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 12:22:36 by vgosset           #+#    #+#             */
/*   Updated: 2016/10/26 15:13:07 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	push_up_sort(int *t, int len)
{
	int		i;

	i = -1;
	while (++i < len - 1)
		t[i] = t[i + 1];
	t[len - 1] = 0;
}

void	push_back_sort(int *t, int len)
{
	while (--len > 0)
		t[len] = t[len - 1];
	t[len] = 0;
}
