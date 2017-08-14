/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:02:48 by fkao              #+#    #+#             */
/*   Updated: 2017/08/11 13:19:24 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_calc
{
	double		cre;
	double		cim;
	double		re1;
	double		re2;
	double		im1;
	double		im2;
}				t_calc;

typedef struct	s_ftal
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*pix;
	int			bpp;
	int			size;
	int			endian;
	int			type;
	char		**name;
	double		w;
	double		h;
	double		zoom;
	int			ite;
	int			x;
	int			y;
	int			mouse;
	int			color;
	int			cycle;
	double		xoff;
	double		yoff;
	t_calc		*c;
}				t_ftal;

void			ftal_draw(t_ftal *e);
int				ftal_map(t_ftal *e, t_calc *c);
int				ftal_iter_abs(t_ftal *e, t_calc *c);
int				ftal_iter_bar(t_ftal *e, t_calc *c);
int				ftal_barcube(t_ftal *e, t_calc *c, int x, int y);
int				ftal_color(t_ftal *e, int i);
void			ftal_note(t_ftal *e);
int				motion_hook(int x, int y, t_ftal *e);
int				ftal_key_funct(int code, t_ftal *e);
int				ftal_mouse_funct(int code, int x, int y, t_ftal *e);
int				ftal_error(int i);
#endif
