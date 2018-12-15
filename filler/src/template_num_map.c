/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template_num_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:09:04 by oriabyi           #+#    #+#             */
/*   Updated: 2018/11/13 15:09:06 by oriabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			fill_template_num_map(t_filler *filler, int nm_y, int y_map)
{
	int				nm_x;
	int				x_map;

	nm_x = 0;
	x_map = 0;
	filler->num_map[nm_y] = (int *)malloc(sizeof(int) * filler->map.size_x);
	if (filler->num_map[nm_y] == NULL)
		return ;
	while (filler->map.map[y_map][x_map])
	{
		if (IS_MY_SIGN(filler->map.map[y_map][x_map]))
		{
			filler->num_map[nm_y][nm_x] = ME;
		}
		else if (IS_FOES_SIGN(filler->map.map[y_map][x_map]))
		{
			filler->num_map[nm_y][nm_x] = ENEMY;
		}
		else
		{
			filler->num_map[nm_y][nm_x] = POINT;
		}
		x_map++;
		nm_x++;
	}
}

void				init_template_num_map(t_filler *filler)
{
	int				y_map;
	int				nm_y;

	nm_y = 0;
	y_map = 0;
	filler->num_map = (int **)malloc(sizeof(int *) * (filler->map.size_y + 1));
	if (filler->num_map == NULL)
		return ;
	while (filler->map.map[y_map])
	{
		fill_template_num_map(filler, nm_y, y_map);
		nm_y++;
		y_map++;
		if (y_map == filler->map.size_y)
		{
			break ;
		}
	}
	filler->num_map[y_map] = NULL;
	init_num_map(filler);
}
