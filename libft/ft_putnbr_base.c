/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicpark <emmet.urssu@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:43:54 by kicpark           #+#    #+#             */
/*   Updated: 2021/04/18 18:43:54 by kicpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_nbase(long my_nbr, long size, char *base)
{
	int		i;
	char	converted[50];

	i = 0;
	while (my_nbr != 0)
	{
		converted[i] = base[my_nbr % size];
		my_nbr = my_nbr / size;
		i++;
	}
	while (i > 0)
	{
		write(1, &converted[i - 1], 1);
		i--;
	}
}

void	ft_putnbr_base(long nbr, char *base)
{
	long	size;
	long	my_nbr;

	size = ft_strlen(base);
	if (!size)
		return ;
	my_nbr = (long)nbr;
	if (my_nbr == 0)
	{
		write(1, &base[0], 1);
	}
	else if (my_nbr < 0)
	{
		my_nbr = (long)UINT_MAX + 1 + my_nbr;
		print_nbase(my_nbr, size, base);
	}
	else
		print_nbase(my_nbr, size, base);
}
