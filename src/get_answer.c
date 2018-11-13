/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_answer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:41:05 by ariabyi           #+#    #+#             */
/*   Updated: 2018/11/13 16:42:11 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int						check_points(t_choices *choices,
								t_filler *filler, int i, int j)
{
	int					x_map;
	int					y_map;

	x_map = choices->x;
	y_map = choices->y;
	while (i < filler->piece.size_y && filler->piece.real_piece
		&& filler->piece.real_piece[i] && filler->piece.real_piece[i][j])
	{
		while (filler->piece.real_piece && filler->piece.real_piece[i]
			&& filler->piece.real_piece[i][j])
		{
			if (filler->bfs == NULL || filler->bfs[y_map] == NULL)
				return (-1);
			if (filler->piece.real_piece[i][j] != '.')
				choices->points += filler->bfs[y_map][x_map];
			j++;
			x_map++;
		}
		i++;
		j = 0;
		x_map = choices->x;
		y_map++;
	}
	return (1);
}

static int				dn(int *i, int *j, int *n_map, int code)
{
	if (code == 1)
		*j = 0;
	(*i)++;
	(*n_map)++;
	return (0);
}

int						check_touches(t_filler *filler,
							int ym, int xm, int touches)
{
	int					x_got;
	int					i;
	int					j;

	i = 0;
	j = 0;
	x_got = xm;
	while (i <= (filler->piece.end_y - filler->piece.start_y + 1))
	{
		while (filler->piece.real_piece && filler->piece.real_piece[i]
		&& filler->piece.real_piece[i][j] && j <= filler->piece.end_x)
		{
			if (ym >= filler->map.size_y || xm >= filler->map.size_x
				|| filler->map.map[ym][xm] == 0)
				return (0);
			if (ISMYSIGN(filler->map.map[ym][xm]) &&
				filler->piece.real_piece[i][j] != '.' && ++touches > 1)
				return (0);
			if (ISFOESSIGN(filler->map.map[ym][xm]) || dn(&j, 0, &xm, 0))
				return (0);
		}
		dn(&i, &j, &ym, 1);
		xm = x_got;
	}
	return (touches);
}

void					get_push_to_ll(t_filler *filler,
								int y_offset, int x_offset)
{
	t_choices			*choices;

	choices = (t_choices *)malloc(sizeof(t_choices));
	choices->x = x_offset;
	choices->y = y_offset;
	if (check_points(choices, filler, 0, 0) == -1)
	{
		free(choices);
		return ;
	}
	choices->next = filler->choices;
	filler->choices = choices;
}

void					real_work(t_filler *filler)
{
	int					x;
	int					y;

	y = 0;
	while (y < filler->map.size_y)
	{
		x = 0;
		while (x < filler->map.size_x)
		{
			if (check_touches(filler, y, x, 0))
			{
				get_push_to_ll(filler, y, x);
			}
			x++;
		}
		y++;
	}
}
