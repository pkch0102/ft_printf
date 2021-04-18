/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicpark <emmet.urssu@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:43:45 by kicpark           #+#    #+#             */
/*   Updated: 2021/04/18 18:43:45 by kicpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_n(char c, int n)
{
	int		i;

	i = 0;
	while (i < n)
		i += ft_putchar(c);
	return (n);
}