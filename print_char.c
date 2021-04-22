/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicpark <kicpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:19:18 by kicpark           #+#    #+#             */
/*   Updated: 2021/04/22 14:22:07 by kicpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_char(int c, t_info *info)
{
	int		res;

	res = 0;
	if (info->type == '%' && info->minus == 1)
		info->zero = 0;
	if (info->minus == 1)
		res += ft_putchar(c);
	res += put_width(info->width, 1, info->zero);
	if (info->minus == 0)
		res += ft_putchar(c);
	return (res);
}

int			put_width(int width, int len, int zero)
{
	int		res;

	res = 0;
	while (len < width)
	{
		if (zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len++;
		res++;
	}
	return (res);
}
