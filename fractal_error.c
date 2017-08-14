/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 15:02:04 by fkao              #+#    #+#             */
/*   Updated: 2017/08/11 12:47:27 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		ftal_error(int i)
{
	if (i == 1)
		ft_putendl("error: input");
	ft_putendl("usage: ./fractol [1:Julia, 2:Mandelbrot, 3:Burning Ship,");
	ft_putendl("\t\t  4:Tricorn, 5:Julia Cube, 6:Mandelbrot Cube,");
	ft_putendl("\t\t  7:Mandelbar Cube, 8:Burning Julia, 9:Juliabar]");
	return (0);
}
