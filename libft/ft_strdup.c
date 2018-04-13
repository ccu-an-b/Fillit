/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgounand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 10:25:01 by jgounand          #+#    #+#             */
/*   Updated: 2017/11/09 19:42:13 by jgounand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	int		index;
	char	*str;

	index = 0;
	while (src[index])
		index++;
	str = (char*)malloc(sizeof(*str) * index + 1);
	if (!str)
		return (NULL);
	ft_strcpy(str, src);
	return (str);
}
