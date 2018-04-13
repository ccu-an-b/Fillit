/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgounand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:43:37 by jgounand          #+#    #+#             */
/*   Updated: 2018/01/29 13:22:36 by ccu-an-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_form	*ft_frm_read(char buff[23])
{
	int		i;
	int		cpt;
	t_form	*frm;

	cpt = 0;
	i = 0;
	if ((frm = (t_form *)ft_memalloc(sizeof(t_form))) == 0)
		return (NULL);
	if (buff[20] != '\0' && buff[20] != '\n')
		print_error();
	while (++i <= 20)
	{
		if ((i % 5 == 0 && buff[i - 1] != '\n') || (i % 5 != 0 &&
					buff[i - 1] != '.' && buff[i - 1] != '#'))
			print_error();
		if (buff[i - 1] == '#')
		{
			ft_frm_fill_cont(frm, cpt, i - 1);
			cpt++;
		}
	}
	ft_frm_test(frm);
	return (frm);
}

void	readfile(char *argv[], t_list **lst)
{
	int		fd;
	int		count;
	char	buff[23];
	t_form	*frm;
	int		end;

	end = 0;
	count = 0;
	if ((fd = open(argv[1], O_RDWR)) == -1)
		print_error();
	ft_bzero(buff, 22);
	while (read(fd, buff, 21))
	{
		frm = ft_frm_read(buff);
		frm->letter = 'A' + count;
		count++;
		ft_lstaddback(lst, ft_lstnew(frm, sizeof(t_form)));
		if (buff[20] == '\0' && buff[19])
			end = 1;
		ft_bzero(buff, 21);
	}
	if (end == 0)
		print_error();
}
