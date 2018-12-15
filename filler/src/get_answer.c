/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_answer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:41:05 by oriabyi           #+#    #+#             */
/*   Updated: 2018/11/13 16:42:11 by oriabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int						check_points(t_choices *choices,
								t_filler *filler, int y, int x)
{
	int					x_map;
	int					y_map;

	x_map = choices->x;
	y_map = choices->y;
	while (y < filler->piece.size_y && filler->piece.real_piece
		&& filler->piece.real_piece[y] && filler->piece.real_piece[y][x])
	{
		while (filler->piece.real_piece && filler->piece.real_piece[y]
			&& filler->piece.real_piece[y][x])
		{
			if (filler->num_map == NULL || filler->num_map[y_map] == NULL)
				return (-1);
			if (filler->piece.real_piece[y][x] != '.')
				choices->points += filler->num_map[y_map][x_map];
			x++;
			x_map++;
		}
		y++;
		x = 0;
		x_map = choices->x;
		y_map++;
	}
	return (1);
}


int						check_touches(t_filler *filler,
							int ym, int xm, int touches)
{
	int					x_got;
	int					y;
	int					x;

	y = 0;
	x = 0;
	x_got = xm;
	while (y <= (filler->piece.end_y - filler->piece.start_y + 1))
	{
		while (filler->piece.real_piece && filler->piece.real_piece[y]
		&& filler->piece.real_piece[y][x] && x <= filler->piece.end_x)
		{
			if (ym >= filler->map.size_y || xm >= filler->map.size_x
				|| filler->map.map[ym][xm] == 0)
			{
				return (0);
			}
			if (IS_MY_SIGN(filler->map.map[ym][xm]) &&
				filler->piece.real_piece[y][x] != '.' && ++touches > 1)
			{
				return (0);
			}
			if (IS_FOES_SIGN(filler->map.map[ym][xm]))
			{
				return (0);
			}
			x++;
			xm++;
		}
		y++;
		x = 0;
		ym++;
		xm = x_got;
	}
	return (touches);
}

void					get_push_to_answer_list(t_filler *filler,
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
				get_push_to_answer_list(filler, y, x);
			}
			x++;
		}
		y++;
	}
}
