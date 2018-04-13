/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgounand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:49:05 by jgounand          #+#    #+#             */
/*   Updated: 2017/12/01 11:02:33 by ccu-an-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

void	ft_printlst(t_list *lst, unsigned int position)
{
	int		i;
	t_form	*frm;

	i = 0;
	while (position > 1 && lst)
	{
		if (lst->next)
			lst = lst->next;
		position--;
	}
	frm = lst->content;
	while (i < 4)
	{
		ft_putnbr(frm->tab_x[i]);
		ft_putnbr(frm->tab_y[i]);
		ft_putstr(" ");
		i++;
	}
}

int		ft_lstsize(t_list *lst)
{
	int	cpt;

	cpt = 0;
	while (lst)
	{
		lst = lst->next;
		cpt++;
	}
	return (cpt);
}
