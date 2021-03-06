/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicpark <kicpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:16:49 by kicpark           #+#    #+#             */
/*   Updated: 2021/04/22 13:17:04 by kicpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_pointer_prefix(char **buf)
{
	*buf = ft_strjoin("0x", *buf, 2);
	return (ft_strlen(*buf));
}

int			put_minus(t_info *info, char **buf)
{
	int		len_to_add;

	len_to_add = 0;
	if ((info->type == 'i' || info->type == 'd') &&
					info->zero == 0 && info->nbr_sign == -1)
	{
		*buf = ft_strjoin("-", *buf, 2);
		len_to_add = 1;
	}
	return (len_to_add);
}

int			put_minus2(int buf_len, t_info *info, char **buf)
{
	int		len_to_add;

	len_to_add = 0;
	if (info->nbr_sign == -1 && info->zero == 1)
	{
		if (buf_len >= info->width)
		{
			*buf = ft_strjoin("-", *buf, 2);
			len_to_add = 1;
		}
		else if (buf_len < info->width)
			*buf[0] = '-';
	}
	return (len_to_add);
}

int			put_prec_str(unsigned long long nbr, t_info *info, char **buf)
{
	int		buf_len;
	int		res;
	int		i;

	buf_len = ft_nbrlen(nbr, info);
	res = (info->prec > buf_len) ? info->prec : buf_len;
	if (!(*buf = (char *)malloc(sizeof(char) * res + 1)))
		return (0);
	i = 0;
	(*buf)[res] = '\0';
	while (buf_len + i < res)
	{
		(*buf)[i] = '0';
		i++;
	}
	i = 1;
	if (nbr == 0 && info->prec != 0)
		(*buf)[res - i] = '0';
	while (nbr)
	{
		(*buf)[res - i] = ft_baseset(info->type)[nbr % info->nbr_base];
		nbr /= info->nbr_base;
		i++;
	}
	return (buf_len);
}

int			print_nbr(unsigned long long nbr, t_info *info)
{
	char	*buf;
	int		buf_len;
	int		res;

	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->nbr_base = 16;
	if ((info->type == 'd' || info->type == 'i') && (int)nbr < 0)
	{
		info->nbr_sign = -1;
		nbr = -nbr;
	}
	buf_len = put_prec_str(nbr, info, &buf);
	buf_len += put_minus(info, &buf);
	if (info->type == 'p')
		buf_len = put_pointer_prefix(&buf);
	res = put_width_str(&buf, info);
	res += put_minus2(buf_len, info, &buf);
	ft_putstr(buf);
	free(buf);
	return (res);
}
