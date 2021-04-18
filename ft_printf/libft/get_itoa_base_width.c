/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_itoa_base_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicpark <emmet.urssu@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:44:44 by kicpark           #+#    #+#             */
/*   Updated: 2021/04/18 18:44:44 by kicpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_itoa_base_width(long n, long size)
{
	int			i;
	long long	long_n;

	i = n < 1 ? 1 : 0;
	n = n < 0 ? -n : n;
	long_n = n < 0 ? -(long long)n : (long long)n;
	while (long_n != 0)
	{
		long_n = long_n / size;
		i++;
	}
	return (i);
}

/*
** get return value except '-' sign to meet 'prcs' requiremnet
*/
