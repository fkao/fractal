/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 13:48:55 by fkao              #+#    #+#             */
/*   Updated: 2017/08/11 13:50:20 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ftal_note(t_ftal *e)
{
	if (e->type == 1 || e->type == 5 || e->type == 8 ||
		e->type == 9)
	{
		mlx_string_put(e->mlx, e->win, 10, 10, 0xFFFFFF, "x:");
		mlx_string_put(e->mlx, e->win, 10, 30, 0xFFFFFF, "y:");
		mlx_string_put(e->mlx, e->win, 40, 10, 0xFFFFFF,
			ft_itoa(e->x - e->w / 2));
		mlx_string_put(e->mlx, e->win, 40, 30, 0xFFFFFF,
			ft_itoa(e->h / 2 - e->y));
		mlx_string_put(e->mlx, e->win, 550, 50, 0xFFFFFF, "space: \
			mouse on/off");
	}
	mlx_string_put(e->mlx, e->win, 550, 10, 0xFFFFFF, "shift: change \
		pallet");
	mlx_string_put(e->mlx, e->win, 550, 30, 0xFFFFFF, "a/s: \
		rotate colors");
}

void	ftal_draw(t_ftal *e)
{
	(e->img) ? mlx_destroy_image(e->mlx, e->img) : 0;
	e->img = mlx_new_image(e->mlx, e->w, e->h);
	e->pix = (int*)mlx_get_data_addr(e->img, &e->bpp, &e->size,
		&e->endian);
	e->c = (t_calc*)ft_memalloc(sizeof(t_calc));
	ftal_map(e, e->c);
	free(e->c);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ftal_note(e);
}

void	ftal_init_image(t_ftal *e)
{
	if (e->type == 1)
	{
		e->x = 252;
		e->y = 344;
	}
	if (e->type == 2)
		e->xoff = 0.5;
	if (e->type == 3)
	{
		e->zoom = 15;
		e->xoff = 1.75;
		e->ite = 36;
	}
	if (e->type == 4)
		e->zoom = 0.75;
	if (e->type == 5)
	{
		e->x = 490;
		e->y = 414;
	}
	if (e->type == 8 || e->type == 9)
	{
		e->x = 472;
		e->y = 183;
	}
}

void	fractal(t_ftal *e)
{
	int	i;

	e->name = ft_strsplit("Julia Set|Mandelbrot Set|Burning Ship|Tricorn|\
		Julia Cube|Mandelbrot Cube|Mandelbar Cube|Burning Julia|Juliabar", '|');
	e->mlx = mlx_init();
	e->w = 800;
	e->h = 600;
	e->win = mlx_new_window(e->mlx, e->w, e->h,
		e->name[e->type - 1]);
	i = 0;
	while (i < 9)
		ft_strdel(&e->name[i++]);
	e->ite = 48;
	e->zoom = 1;
	ftal_init_image(e);
	ftal_draw(e);
	mlx_hook(e->win, 2, 0, ftal_key_funct, e);
	mlx_hook(e->win, 4, 0, ftal_mouse_funct, e);
	mlx_hook(e->win, 6, 0, motion_hook, e);
	mlx_loop(e->mlx);
}

int		main(int ac, char **av)
{
	t_ftal	*e;
	int		i;

	e = (t_ftal*)ft_memalloc(sizeof(t_ftal));
	if (ac > 1)
	{
		i = 0;
		while (++i < ac)
		{
			if (ft_strcmp(av[i], "1") && ft_strcmp(av[i], "2") &&
				ft_strcmp(av[i], "3") && ft_strcmp(av[i], "4") &&
				ft_strcmp(av[i], "5") && ft_strcmp(av[i], "6") &&
				ft_strcmp(av[i], "7") && ft_strcmp(av[i], "8") &&
				ft_strcmp(av[i], "9"))
				return (ftal_error(1));
			e->type = ft_atoi(av[i]);
			if (fork() == 0)
				fractal(e);
		}
	}
	else
		return (ftal_error(0));
	return (0);
}
