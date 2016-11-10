/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sample.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:47:52 by vgosset           #+#    #+#             */
/*   Updated: 2016/11/10 15:01:46 by vgosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		fusion_help(int *begin2, int *cpt2, int mid, int begin)
{
	*begin2 = mid + 1;
	*cpt2 = *begin2;
	return (begin);
}

static void		fusion(int *lst, int beg, int mid, int end)
{
	int		*tmp;
	int		beg2;
	int		cpt1;
	int		cpt2;
	int		i;

	tmp = (int *)ft_memalloc(sizeof(int) * (mid - beg + 1));
	cpt1 = fusion_help(&beg2, &cpt2, mid, beg);
	i = beg - 1;
	while (++i <= mid)
		tmp[i - beg] = lst[i];
	i = beg - 1;
	while (++i <= end)
	{
		if (cpt1 == beg2)
			break ;
		else if (cpt2 == (end + 1))
			lst[i] = tmp[cpt1++ - beg];
		else if (tmp[cpt1 - beg] < lst[cpt2])
			lst[i] = tmp[cpt1++ - beg];
		else
			lst[i] = lst[cpt2++];
	}
	ft_memdel((void **)&tmp);
}

static void		fusion_sort(int *lst, int beg, int end)
{
	int		mid;

	if (end != beg)
	{
		mid = (end + beg) / 2;
		fusion_sort(lst, beg, mid);
		fusion_sort(lst, mid + 1, end);
		fusion(lst, beg, mid, end);
	}
}

void			sort_sample_list(int *lst, int beg, int end)
{
	if (end > 0)
		fusion_sort(lst, beg, end);
}
