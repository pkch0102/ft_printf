/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_7_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicpark <emmet.urssu@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:49:48 by kicpark           #+#    #+#             */
/*   Updated: 2021/04/18 18:49:48 by kicpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*process_width(t_tag *tag, char *box, char c)
{
	if (tag->width < 2)
		tag->width = 1;
	if (tag->left_aligned == DISABLED && tag->zero_fill == ENABLED)
		tag->padding = '0';
	box = fill_box(tag->width, tag->padding);
	if (box == NULL)
		return (NULL);
	if (tag->left_aligned == ENABLED)
		box[0] = c;
	else
		box[tag->width - 1] = c;
	return (box);
}

int			print_percent(t_tag *tag)
{
	char	c;
	char	*res;
	t_box	*box;

	c = '%';
	box = prepare_box();
	if ((res = process_width(tag, box->width, c)) == NULL)
	{
		free_box(box);
		return (ERROR);
	}
	tag->nbyte += ft_putstr_n(res, ft_strlen(res));
	free_box(box);
	return (0);
}
