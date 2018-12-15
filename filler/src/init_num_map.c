/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_num_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:09:06 by oriabyi           #+#    #+#             */
/*   Updated: 2018/11/13 15:09:07 by oriabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void				fill_cell_num_map(t_filler *filler,
										int y, int *x, int num)
{
	if (filler->num_map[y][(*x)] == num)
	{
		if ((*x) + 1 < filler->map.size_x && filler->num_map[y][(*x) + 1] == POINT)
			filler->num_map[y][(*x) + 1] = num + 1;
		if ((*x) - 1 >= 0 && filler->num_map[y][(*x) - 1] == POINT)
			filler->num_map[y][(*x) - 1] = num + 1;
		if (y + 1 < filler->map.size_y && filler->num_map[y + 1][(*x)] == POINT)
			filler->num_map[y + 1][(*x)] = num + 1;
		if (y - 1 >= 0 && filler->num_map[y - 1][(*x)] == POINT)
			filler->num_map[y - 1][(*x)] = num + 1;
		if (y - 1 >= 0 && (*x) + 1 < filler->map.size_x
			&& filler->num_map[y - 1][(*x) + 1] == POINT)
		{
			filler->num_map[y - 1][(*x) + 1] = num + 1;
		}
		if (y - 1 >= 0 && (*x) - 1 >= 0 &&
			filler->num_map[y - 1][(*x) - 1] == POINT)
		{
			filler->num_map[y - 1][(*x) - 1] = num + 1;
		}
		if (y + 1 < filler->map.size_y && (*x) + 1 < filler->map.size_x
			&& filler->num_map[y + 1][(*x) + 1] == POINT)
		{
			filler->num_map[y + 1][(*x) + 1] = num + 1;
		}
		if (y + 1 < filler->map.size_y && (*x) - 1 >= 0
			&& filler->num_map[y + 1][(*x) - 1] == POINT)
		{
			filler->num_map[y + 1][(*x) - 1] = num + 1;
		}
	}
	(*x)++;
}

void				fill_num_map(t_filler *filler)
{
	int				y;
	int				x;
	int				num;

	num = -1;
	y = 0;
	while (y < filler->map.size_y &&
		   num < filler->map.size_y + filler->map.size_x)
	{
		x = 0;
		while (x < filler->map.size_x)
		{
			fill_cell_num_map(filler, y, &x, num);
		}
		if (++y == filler->map.size_y)
		{
			if (ft_check_iarr(filler->num_map,
							filler->map.size_x,
							filler->map.size_y, POINT))
			{
				y = 0;
				num++;
			}
		}
	}
}

void				reassignment_honed_cells(t_filler *filler)
{
	int				y;
	int				x;

	y = 0;
	while (y < filler->map.size_y)
	{
		x = 0;
		while (x < filler->map.size_x)
		{
			if (filler->num_map[y][x] == POINT)
				filler->num_map[y][x] = 99;
			x++;
		}
		y++;
	}
}

void				init_num_map(t_filler *filler)
{
	fill_num_map(filler);
	reassignment_honed_cells(filler);
}
