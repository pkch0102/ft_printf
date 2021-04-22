/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicpark <kicpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 14:19:40 by kicpark           #+#    #+#             */
/*   Updated: 2021/04/22 14:26:55 by kicpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					print_type(va_list ap, t_info *info)
{
	int				res;
	char			type;

	res = 0;
	type = info->type;
	if (type == 'c')
		res = print_char(va_arg(ap, int), info);
	else if (type == '%')
		res = print_char('%', info);
	else if (type == 's')
		res = print_string(va_arg(ap, char *), info);
	else if (type == 'd' || type == 'i')
		res = print_nbr(va_arg(ap, int), info);
	else if (type == 'x' || type == 'X' || type == 'u')
		res = print_nbr(va_arg(ap, unsigned int), info);
	else if (type == 'p')
		res = print_nbr(va_arg(ap, unsigned long long), info);
	return (res);
}

void				check_width_and_prec(va_list ap,
		char *format, t_info *info, int i)
{
	if (ft_isdigit(format[i]))
	{
		if (info->prec == -1)
			info->width = info->width * 10 + format[i] - 48;
		else
			info->prec = info->prec * 10 + format[i] - 48;
	}
	else if (format[i] == '*')
	{
		if (info->prec == -1)
		{
			info->width = va_arg(ap, int);
			if (info->width < 0)
			{
				info->minus = 1;
				info->width *= -1;
			}
		}
		else
			info->prec = va_arg(ap, int);
	}
}

void				check_info(va_list ap, char *format, t_info *info, int i)
{
	if (format[i] == '0' && info->width == 0 && info->prec == -1)
		info->zero = 1;
	else if (format[i] == '-')
		info->minus = 1;
	else if (format[i] == '.')
		info->prec = 0;
	else if (ft_isdigit(format[i]) || format[i] == '*')
		check_width_and_prec(ap, format, info, i);
}

int					parse_format(va_list ap, char *format)
{
	int				i;
	int				res;
	t_info			*info;

	i = 0;
	res = 0;
	if (!(info = malloc(sizeof(t_info) * 1)))
		return (-1);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			res += ft_putchar(format[i++]);
		if (format[i] == '%')
		{
			init_info(info);
			while (format[++i] != '\0' && !(ft_strchr(TYPE, format[i])))
				check_info(ap, format, info, i);
			info->type = format[i++];
			if ((info->minus == 1 || info->prec > -1) && info->type != '%')
				info->zero = 0;
			res += print_type(ap, info);
		}
	}
	free(info);
	return (res);
}

int					ft_printf(const char *format, ...)
{
	int				res;
	va_list			ap;

	va_start(ap, format);
	res = parse_format(ap, (char *)format);
	va_end(ap);
	return (res);
}
