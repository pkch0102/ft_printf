/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_itoa_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicpark <emmet.urssu@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:44:48 by kicpark           #+#    #+#             */
/*   Updated: 2021/04/18 18:44:48 by kicpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_itoa_width(long n)
{
	int		i;

	i = n < 1 ? 1 : 0;
	n = n < 0 ? -n : n;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

/*
** line 15 : change from 'int' to 'long' to pass test 640 with long numbers
*/
