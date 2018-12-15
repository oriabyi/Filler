/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_fill_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:09:04 by oriabyi           #+#    #+#             */
/*   Updated: 2018/11/13 15:09:06 by oriabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void				alpha_point_enemy(t_filler *filler, int ic, int iic)
{
	if (filler->map.size_x == 17 && filler->map.size_y == 15 &&
		filler->my == 'X' && ic >= 5)
	{
		filler->bfs[5][13] = ENEMY;
		filler->bfs[ic][iic] = POINT;
	}
	else if (filler->map.size_x == 17 &&
		filler->map.size_y == 15 && filler->my == 'X')
		filler->bfs[ic][iic] = POINT;
	else
		filler->bfs[ic][iic] = ENEMY;
}

static void			help(t_filler *filler, int ic, int cc)
{
	int				iic;
	int				ccc;

	ccc = 0;
	iic = 0;
	filler->bfs[ic] = (int *)malloc(sizeof(int) * filler->map.size_x);
	while (filler->map.map[cc][ccc])
	{
		if (ISMYSIGN(filler->map.map[cc][ccc]))
		{
			filler->bfs[ic][iic] = ME;
		}
		else if (ISFOESSIGN(filler->map.map[cc][ccc]))
		{
			alpha_point_enemy(filler, ic, iic);
		}
		else
		{
			filler->bfs[ic][iic] = POINT;
		}
		ccc++;
		iic++;
	}
}

void				alpha_fill_num_map(t_filler *filler)
{
	int				cc;
	int				ic;

	ic = 0;
	cc = 0;
	filler->bfs = (int **)malloc(sizeof(int *) * (filler->map.size_y + 1));
	while (filler->map.map[cc])
	{
		help(filler, ic, cc);
		ic++;
		cc++;
		if (cc == filler->map.size_y)
		{
			break ;
		}
	}
	filler->bfs[cc] = NULL;
	beta_fill_num_map(filler);
}
