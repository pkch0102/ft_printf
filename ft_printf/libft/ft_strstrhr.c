/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrhr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicpark <emmet.urssu@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:44:30 by kicpark           #+#    #+#             */
/*   Updated: 2021/04/18 18:44:30 by kicpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstrhr(const char *s, char *set)
{
	int i;
	int j;

	if (s == 0)
		return (0);
	i = 0;
	if (set == 0)
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		j = 0;
		while (set[j])
		{
			if (s[i] == set[j])
				return ((char *)s + i);
			j++;
		}
		i++;
	}
	return (0);
}
