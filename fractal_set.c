/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 10:45:28 by fkao              #+#    #+#             */
/*   Updated: 2017/08/11 13:18:53 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ftal_iter_cube(t_ftal *e, t_calc *c)
{
	int	i;

	i = 0;
	while (i < e->ite)
	{
		c->re2 = (c->re1 * c->re1 * c->re1) - (3 * c->re1 * c->im1 * c->im1)
			+ c->cre;
		c->im2 = (3 * c->re1 * c->re1 * c->im1) - (c->im1 * c->im1 * c->im1)
			+ c->cim;
		if ((c->re2 * c->re2 + c->im2 * c->im2) > 4)
			break ;
		c->re1 = c->re2;
		c->im1 = c->im2;
		i++;
	}
	return (i);
}

int	ftal_iterate(t_ftal *e, t_calc *c)
{
	int	i;

	i = 0;
	while (i < e->ite)
	{
		c->re2 = c->re1 * c->re1 - c->im1 * c->im1 + c->cre;
		c->im2 = 2 * c->re1 * c->im1 + c->cim;
		if ((c->re2 * c->re2 + c->im2 * c->im2) > 4)
			break ;
		c->re1 = c->re2;
		c->im1 = c->im2;
		i++;
	}
	return (i);
}

int	ftal_mandelbrot(t_ftal *e, t_calc *c, int x, int y)
{
	c->re1 = 0;
	c->im1 = 0;
	c->cre = 2 * (2 * x - e->w) / (e->zoom * e->w) - e->xoff;
	c->cim = 1.5 * (2 * y - e->h) / (e->zoom * e->h) - e->yoff;
	if (e->type == 3 || e->type == 4)
		return ((e->type == 3) ? ftal_iter_abs(e, c) : ftal_iter_bar(e, c));
	return ((e->type == 2) ? ftal_iterate(e, c) : ftal_iter_cube(e, c));
}

int	ftal_julia(t_ftal *e, t_calc *c, int x, int y)
{
	c->re1 = 2 * (2 * x - e->w) / (e->zoom * e->w) - e->xoff;
	c->im1 = 1.5 * (2 * y - e->h) / (e->zoom * e->h) - e->yoff;
	c->cre = 2 * (2 * e->x - e->w) / e->w;
	c->cim = 1.5 * (2 * e->y - e->h) / e->h;
	if (e->type == 8 || e->type == 9)
		return ((e->type == 8) ? ftal_iter_abs(e, c) : ftal_iter_bar(e, c));
	return ((e->type == 1) ? ftal_iterate(e, c) : ftal_iter_cube(e, c));
}

int	ftal_map(t_ftal *e, t_calc *c)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (y < e->h)
	{
		x = 0;
		while (x < e->w)
		{
			if (e->type == 1 || e->type == 5 || e->type == 8 ||
				e->type == 9)
				i = ftal_julia(e, c, x, y);
			if (e->type == 2 || e->type == 3 || e->type == 4 ||
				e->type == 6)
				i = ftal_mandelbrot(e, c, x, y);
			if (e->type == 7)
				i = ftal_barcube(e, c, x, y);
			e->pix[x + y * e->size / 4] = ftal_color(e, i);
			x++;
		}
		y++;
	}
	return (0);
}
