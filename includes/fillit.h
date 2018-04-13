/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgounand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:25:12 by jgounand          #+#    #+#             */
/*   Updated: 2017/11/28 13:26:13 by jgounand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef	struct		s_form
{
	int		tab_x[4];
	int		tab_y[4];
	char	letter;
}					t_form;

typedef	struct		s_sol
{
	int		size;
	int		nbfrm;
	int		nbfrmok;
	char	**tab;
}					t_sol;

void				ft_print_tab(t_sol *sol);
void				ft_sol_init(t_sol *sol, t_list *lst);
int					ft_is_empty(char **tab, int x, int y);
int					ft_frm_ok(t_form *frm, t_sol *sol, int x, int y);
void				print_error(void);
void				ft_frm_fill_cont(t_form *frm, int cpt, int i);
void				ft_frm_test(t_form *frm);
void				ft_strpint2dim(char **str, size_t size);
void				readfile(char *arv[], t_list **lst);
void				ft_printlst(t_list *lst, unsigned int position);
int					ft_lstsize(t_list *lst);
int					ft_tab_size(int n);
int					ft_solver(t_list *lst, t_sol *sol, int pos);
void				ft_fill_tab(t_list *lst, t_sol *sol, int pos, char c);
#endif
