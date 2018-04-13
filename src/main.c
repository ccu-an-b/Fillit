/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgounand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:34:54 by jgounand          #+#    #+#             */
/*   Updated: 2017/12/01 11:02:23 by ccu-an-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int arc, char *arv[])
{
	t_list	*lst;
	t_sol	*sol;

	lst = NULL;
	if (arc != 2)
	{
		ft_putstr("usage: ./fillit file\n");
		exit(0);
	}
	readfile(arv, &lst);
	sol = malloc(sizeof(t_sol));
	sol->size = ft_tab_size(ft_lstsize(lst) - 1);
	ft_sol_init(sol, lst);
	while (ft_solver(lst, sol, 0) != 1)
	{
		sol->size++;
		free(sol->tab);
		sol->tab = NULL;
		ft_sol_init(sol, lst);
	}
	ft_print_tab(sol);
	return (0);
}
