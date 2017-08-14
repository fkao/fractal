/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 11:30:22 by fkao              #+#    #+#             */
/*   Updated: 2017/08/11 13:20:23 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ftal_exit_funct(int code, t_ftal *e)
{
	if (code == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	return (0);
}

int	ftal_key_funct(int code, t_ftal *e)
{
	ftal_exit_funct(code, e);
	if (code == 49)
		e->mouse = (e->mouse) ? 0 : 1;
	if (code == 0 || code == 1)
		(code == 0) ? e->cycle++ : e->cycle--;
	if (code == 258)
		e->color++;
	if (code == 123 || code == 124)
		e->xoff += ((code == 123) ? 0.1 : -0.1) / e->zoom;
	if (code == 125 || code == 126)
		e->yoff += ((code == 126) ? 0.1 : -0.1) / e->zoom;
	ftal_draw(e);
	return (0);
}

int	ftal_mouse_funct(int code, int x, int y, t_ftal *e)
{
	x -= e->w / 2;
	y -= e->h / 2;
	if (code == 4)
	{
		e->zoom += e->zoom / 10;
		e->xoff -= x / (e->zoom * e->w);
		e->yoff -= y / (e->zoom * e->h);
		e->ite++;
	}
	if (code == 5)
	{
		e->zoom -= e->zoom / 10;
		e->xoff += x / (e->zoom * e->w);
		e->yoff += y / (e->zoom * e->h);
		e->ite--;
	}
	ftal_draw(e);
	return (0);
}

int	motion_hook(int x, int y, t_ftal *e)
{
	if (e->mouse)
	{
		e->x = x;
		e->y = y;
		ftal_draw(e);
	}
	return (0);
}
