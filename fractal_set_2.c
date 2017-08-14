/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_set_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 15:05:04 by fkao              #+#    #+#             */
/*   Updated: 2017/08/11 13:09:15 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ftal_iter_abs(t_ftal *e, t_calc *c)
{
	int	i;

	i = 0;
	while (i < e->ite)
	{
		c->re2 = c->re1 * c->re1 - c->im1 * c->im1 + c->cre;
		c->im2 = ft_absd(2 * c->re1 * c->im1) + c->cim;
		if ((c->re2 * c->re2 + c->im2 * c->im2) > 4)
			break ;
		c->re1 = c->re2;
		c->im1 = c->im2;
		i++;
	}
	return (i);
}

int	ftal_iter_bar(t_ftal *e, t_calc *c)
{
	int	i;

	i = 0;
	while (i < e->ite)
	{
		c->re2 = c->re1 * c->re1 - c->im1 * c->im1 + c->cre;
		c->im2 = c->cim - 2 * c->re1 * c->im1;
		if ((c->re2 * c->re2 + c->im2 * c->im2) > 4)
			break ;
		c->re1 = c->re2;
		c->im1 = c->im2;
		i++;
	}
	return (i);
}

int	ftal_barcube(t_ftal *e, t_calc *c, int x, int y)
{
	int	i;

	c->re1 = 0;
	c->im1 = 0;
	c->cre = 2 * (2 * x - e->w) / (e->zoom * e->w) - e->xoff;
	c->cim = 1.5 * (2 * y - e->h) / (e->zoom * e->h) - e->yoff;
	i = 0;
	while (i < e->ite)
	{
		c->re2 = (c->re1 * c->re1 * c->re1) - (3 * c->re1 * c->im1 * c->im1)
			+ c->cre;
		c->im2 = c->cim - (3 * c->re1 * c->re1 * c->im1) +
			(c->im1 * c->im1 * c->im1);
		if ((c->re2 * c->re2 + c->im2 * c->im2) > 4)
			break ;
		c->re1 = c->re2;
		c->im1 = c->im2;
		i++;
	}
	return (i);
}
