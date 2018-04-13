/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgounand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 14:27:42 by jgounand          #+#    #+#             */
/*   Updated: 2017/11/08 08:50:00 by jgounand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int	nb;
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	nb = 0;
	while (str[i] == '\n' || str[i] == '\f' || str[i] == '\r' ||
			str[i] == '\t' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (neg ? -nb : nb);
}