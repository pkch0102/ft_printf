/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicpark <emmet.urssu@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:42:32 by kicpark           #+#    #+#             */
/*   Updated: 2021/04/18 18:42:32 by kicpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int atoi;
	int sign;

	sign = 1;
	while (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -sign : sign;
		str++;
	}
	atoi = 0;
	if (!is_set(*str, DIGIT))
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		atoi = atoi * 10 + (*str - '0');
		str++;
	}
	return (atoi * sign);
}
