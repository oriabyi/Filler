/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beta_fill_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:09:06 by ariabyi           #+#    #+#             */
/*   Updated: 2018/11/13 15:09:07 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void				help_beta_fill_num_map(t_filler *filler,
										int i, int *j, int num)
{
	if (filler->bfs[i][(*j)] == num)
	{
		if ((*j) + 1 < filler->map.size_x && filler->bfs[i][(*j) + 1] == POINT)
			filler->bfs[i][(*j) + 1] = num + 1;
		if ((*j) - 1 >= 0 && filler->bfs[i][(*j) - 1] == POINT)
			filler->bfs[i][(*j) - 1] = num + 1;
		if (i + 1 < filler->map.size_y && filler->bfs[i + 1][(*j)] == POINT)
			filler->bfs[i + 1][(*j)] = num + 1;
		if (i - 1 >= 0 && filler->bfs[i - 1][(*j)] == POINT)
			filler->bfs[i - 1][(*j)] = num + 1;
		if (i - 1 >= 0 && (*j) + 1 < filler->map.size_x
			&& filler->bfs[i - 1][(*j) + 1] == POINT)
			filler->bfs[i - 1][(*j) + 1] = num + 1;
		if (i - 1 >= 0 && (*j) - 1 >= 0 &&
			filler->bfs[i - 1][(*j) - 1] == POINT)
			filler->bfs[i - 1][(*j) - 1] = num + 1;
		if (i + 1 < filler->map.size_y && (*j) + 1 < filler->map.size_x
			&& filler->bfs[i + 1][(*j) + 1] == POINT)
			filler->bfs[i + 1][(*j) + 1] = num + 1;
		if (i + 1 < filler->map.size_y && (*j) - 1 >= 0
			&& filler->bfs[i + 1][(*j) - 1] == POINT)
			filler->bfs[i + 1][(*j) - 1] = num + 1;
	}
	(*j)++;
}

void				beta_help(t_filler *filler)
{
	int				i;
	int				j;
	int				num;

	num = -1;
	i = 0;
	while (i < filler->map.size_y &&
		num < filler->map.size_y + filler->map.size_x)
	{
		j = 0;
		while (j < filler->map.size_x)
		{
			help_beta_fill_num_map(filler, i, &j, num);
		}
		if (++i == filler->map.size_y)
		{
			if (ft_check_iarr(filler->bfs,
							filler->map.size_x,
							filler->map.size_y, POINT))
			{
				i = 0;
				num++;
			}
		}
	}
}

void				feature_fill_num_map(t_filler *filler)
{
	int				i;
	int				j;

	i = 0;
	while (i < filler->map.size_y)
	{
		j = 0;
		while (j < filler->map.size_x)
		{
			if (filler->bfs[i][j] == POINT)
				filler->bfs[i][j] = 99;
			j++;
		}
		i++;
	}
}

void				beta_fill_num_map(t_filler *filler)
{
	beta_help(filler);
	feature_fill_num_map(filler);
}
