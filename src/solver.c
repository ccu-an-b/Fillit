/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccu-an-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:37:14 by ccu-an-b          #+#    #+#             */
/*   Updated: 2017/12/01 11:05:11 by ccu-an-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_is_empty(char **tab, int x, int y)
{
	if (x < 0 || y < 0)
		return (0);
	if (tab[y][x] == '.')
		return (1);
	return (0);
}

int		ft_frm_ok(t_form *frm, t_sol *sol, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (x + frm->tab_x[i] >= sol->size || y + frm->tab_y[i] >= sol->size)
			return (0);
		if (ft_is_empty(sol->tab, x + frm->tab_x[i], y + frm->tab_y[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_fill_tab(t_list *lst, t_sol *sol, int pos, char c)
{
	int		i;
	int		x;
	int		y;
	t_form	*frm;

	i = 0;
	x = pos % sol->size;
	y = pos / sol->size;
	frm = lst->content;
	while (i < 4)
	{
		sol->tab[y + frm->tab_y[i]][x + frm->tab_x[i]] = c;
		i++;
	}
	if (c == '.')
		sol->nbfrmok--;
}

int		ft_solver(t_list *lst, t_sol *sol, int pos)
{
	int		x;
	int		y;
	t_form	*frm;

	if (!lst && sol->nbfrmok == sol->nbfrm)
		return (1);
	frm = lst->content;
	while (pos != sol->size * sol->size)
	{
		x = pos % sol->size;
		y = pos / sol->size;
		if (ft_frm_ok(frm, sol, x, y) == 1 && ft_is_empty(sol->tab, x, y) == 1)
		{
			ft_fill_tab(lst, sol, pos, frm->letter);
			sol->nbfrmok++;
			if (ft_solver(lst->next, sol, 0))
				return (1);
			else
				ft_fill_tab(lst, sol, pos, '.');
		}
		pos++;
	}
	return (0);
}
