/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccu-an-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:26:11 by ccu-an-b          #+#    #+#             */
/*   Updated: 2017/12/01 11:02:15 by ccu-an-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_tab(t_sol *sol)
{
	int	i;

	i = 0;
	while (i < sol->size)
	{
		ft_putstr(sol->tab[i]);
		ft_putchar('\n');
		i++;
	}
}

int		ft_tab_size(int nbfrm)
{
	int	i;
	int	n;

	n = nbfrm * 4;
	i = 0;
	while (i * i <= n)
	{
		if (i * i == n)
			return (i);
		i++;
	}
	return (i - 1);
}

char	**ft_tab_init(int size)
{
	char	**tab;
	int		i;

	i = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	while (i < size)
	{
		tab[i] = (char*)malloc(sizeof(char) * size + 1);
		if (tab[i])
		{
			ft_memset(tab[i], '.', size);
			tab[i][size] = '\0';
			i++;
		}
	}
	return (tab);
}

void	ft_sol_init(t_sol *sol, t_list *lst)
{
	sol->nbfrm = ft_lstsize(lst);
	sol->nbfrmok = 0;
	sol->tab = ft_tab_init(sol->size);
}
