/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkao <fkao@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 13:19:38 by fkao              #+#    #+#             */
/*   Updated: 2017/08/11 13:19:33 by fkao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		ftal_color3(t_ftal *e, int i)
{
	static int	color[36] = {
		0x22ACF7, 0x6CC5B0, 0xB5DE68, 0xFFF721,
		0xF9D24C, 0xF4AD76, 0xEE88A1, 0xE863CB,
		0xCE7DC4, 0xB498BD, 0x9AB2B6, 0x80CCAF,
		0x969E83, 0xAB7158, 0xC1432C, 0xD61500,
		0xC03911, 0xAA5C22, 0x948033, 0x7EA344,
		0x869165, 0x8F8087, 0x976EA8, 0x9F5CC9,
		0xB7839F, 0xCFAA75, 0xE7D04B, 0xFFF721,
		0xF5BF19, 0xEB8611, 0xE04E08, 0xD61500,
		0xB23331, 0x8E5163, 0x6A7094, 0x468EC6};

	i += 36 + (e->cycle % 36);
	return (color[i % 36]);
}

int		ftal_color2(t_ftal *e, int i)
{
	static int	color[48] = {
		0x1717D1, 0x2E2ED5, 0x4646DA, 0x5D5DDF,
		0x7474E3, 0x8B8BE8, 0xA2A2EC, 0xB9B9F1,
		0xD1D1F6, 0xE8E8FA, 0xFFFFFF, 0xFFFFDB,
		0xFFFFB6, 0xFFFF92, 0xFFFF6D, 0xFFFF49,
		0xFFFF24, 0xFFFF00, 0xFFF100, 0xFFE300,
		0xFFD500, 0xFFC700, 0xFFB900, 0xFFAC00,
		0xFF9E00, 0xFF9000, 0xFF8200, 0xFF7400,
		0xFF6600, 0xF2610A, 0xE65C14, 0xD9571F,
		0xCC5229, 0xBF4C33, 0xB2473D, 0xA64247,
		0x993D52, 0x8C385C, 0x803366, 0x732E70,
		0x66297A, 0x592485, 0x4D1F8F, 0x401A99,
		0x3314A3, 0x260FAD, 0x190AB8, 0x0D05C2};

	i += 48 + (e->cycle % 48);
	return (color[i % 48]);
}

int		ftal_color1(t_ftal *e, int i)
{
	static int	color[48] = {
		0xCC33FF, 0xD138E6, 0xD63DCC, 0xDB42B2,
		0xDE45A6, 0xE34A8C, 0xE64C80, 0xEB5266,
		0xED5459, 0xF25940, 0xF75E26, 0xFC630D,
		0xFF6600, 0xFF7500, 0xFF7D00, 0xFF8500,
		0xFF8C00, 0xFF9C00, 0xFFA300, 0xFFAB00,
		0xFFB200, 0xFFC200, 0xFFC900, 0xFFD100,
		0xFFD900, 0xFFE800, 0xFFF000, 0xFFF700,
		0xFFFF00, 0xFFFF0D, 0xFFFF1A, 0xFFFF26,
		0xFFFF33, 0xFFFF40, 0xFFFF4C, 0xFFFF59,
		0xFFFF66, 0xFFFF73, 0xFFFF80, 0xFFFF8C,
		0xFFFF99, 0xFFFFA6, 0xFFFFB2, 0xFFFFBF,
		0xFFFFCC, 0xFFFFD9, 0xFFFFE6, 0x64FFFF};

	i += 48 + (e->cycle % 48);
	return (color[i % 48]);
}

int		ftal_color0(t_ftal *e, int i)
{
	static int	color[44] = {
		0xFF1500, 0xFF2B00, 0xFF4100, 0xFF5700,
		0xFF6C00, 0xFF8200, 0xFF9800, 0xFFAE00,
		0xFFC200, 0xFFD700, 0xFFEB00, 0xFFFF00,
		0xDFFF00, 0xBFFF00, 0x9FFF00, 0x80FF00,
		0x60FF00, 0x40FF00, 0x20FF00, 0x00FF00,
		0x00FF3F, 0x00FF7D, 0x00FFBC, 0x00FFFA,
		0x00DFFB, 0x00BFFB, 0x009FFC, 0x0080FD,
		0x0060FD, 0x0040FE, 0x0020FE, 0x0000FF,
		0x2600FF, 0x4C00FF, 0x7200FF, 0x9800FF,
		0xB200F6, 0xCC00EE, 0xE500E5, 0xFF00DC,
		0xFF00A5, 0xFF006E, 0xFF0037, 0xFF0000};

	i += 44 + (e->cycle % 44);
	return (color[i % 44]);
}

int		ftal_color(t_ftal *e, int i)
{
	if (i == e->ite)
		return (0x000000);
	if (e->color % 4 == 0)
		return (ftal_color0(e, i));
	if (e->color % 4 == 1)
		return (ftal_color1(e, i));
	if (e->color % 4 == 2)
		return (ftal_color2(e, i));
	if (e->color % 4 == 3)
		return (ftal_color3(e, i));
	return (0);
}
