/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frmtest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccu-an-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:14:15 by ccu-an-b          #+#    #+#             */
/*   Updated: 2017/12/01 11:02:10 by ccu-an-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_tab_clear(int tab[4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		tab[i] = 0;
		i++;
	}
}

void	ft_frm_fill_cont(t_form *frm, int cpt, int i)
{
	if (cpt == 5)
		print_error();
	frm->tab_x[cpt] = i % 5;
	frm->tab_y[cpt] = i / 5;
}

int		ft_frm_check(int touch[4])
{
	int i;
	int touch_2;

	i = 0;
	touch_2 = 0;
	while (i < 4)
	{
		if (touch[i] == 0 || touch[i] > 3)
			return (0);
		else if (touch[i] > 1)
			touch_2++;
		i++;
	}
	if (touch_2 > 0)
		return (1);
	return (0);
}

void	ft_frm_sort(t_form *frm)
{
	while (frm->tab_x[0] != 0)
	{
		frm->tab_x[0]--;
		frm->tab_x[1]--;
		frm->tab_x[2]--;
		frm->tab_x[3]--;
	}
	while (frm->tab_y[0] != 0)
	{
		frm->tab_y[0]--;
		frm->tab_y[1]--;
		frm->tab_y[2]--;
		frm->tab_y[3]--;
	}
}

void	ft_frm_test(t_form *frm)
{
	int i;
	int j;
	int touch[4];

	i = -1;
	j = -1;
	ft_tab_clear(touch);
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (frm->tab_x[i] == frm->tab_x[j] &&
					(frm->tab_y[i] == frm->tab_y[j] + 1 ||
					frm->tab_y[i] == frm->tab_y[j] - 1))
				touch[i] += 1;
			if (frm->tab_y[i] == frm->tab_y[j] &&
					(frm->tab_x[i] == frm->tab_x[j] + 1 ||
					frm->tab_x[i] == frm->tab_x[j] - 1))
				touch[i] += 1;
		}
	}
	if (ft_frm_check(touch) == 0)
		print_error();
	ft_frm_sort(frm);
}
