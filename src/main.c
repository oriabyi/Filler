/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:05:44 by ariabyi           #+#    #+#             */
/*   Updated: 2018/11/13 14:05:45 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void				set_nude_pieces_coord(t_filler *filler)
{
	int				x;
	int				y;

	y = 0;
	filler->piece.start_x = 20000000;
	filler->piece.end_x = 0;
	filler->piece.start_y = -1;
	filler->piece.end_y = 0;
	while (y < filler->piece.size_y && !(x = 0))
	{
		while (x < filler->piece.size_x)
			if (filler->piece.piece[y][x] == '*' || x++ == -1)
			{
				if (x < filler->piece.start_x)
					filler->piece.start_x = x;
				if (x > filler->piece.end_x)
					filler->piece.end_x = x;
				if (filler->piece.start_y == -1)
					filler->piece.start_y = y;
				if (filler->piece.end_y < y)
					filler->piece.end_y = y;
				x++;
			}
		y++;
	}
}

int					check_absolute_cord(t_filler *filler, t_choices *temp)
{
	if (filler->choices->x - temp->x > filler->map.size_x
		|| filler->choices->y - temp->y > filler->map.size_y
		|| filler->choices->x - temp->x < 0
		|| filler->choices->y - temp->y < 0)
		return (0);
	return (1);
}

t_choices			*find_the_best_choice(t_filler *filler)
{
	t_choices		*tiny;
	t_choices		*temp;
	t_choices		*back;

	temp = filler->choices;
	tiny = filler->choices;
	while (temp)
	{
		if (temp->points < tiny->points && check_absolute_cord(filler, temp))
			tiny = temp;
		temp = temp->next;
	}
	if (!tiny || !(back = (t_choices *)malloc(sizeof(t_choices))))
		return (NULL);
	back->x = tiny->x;
	back->y = tiny->y;
	back->next = NULL;
	clean_choices(&filler->choices);
	return (back);
}

int					dop_parsing(t_filler *filler, char *line)
{
	if (ft_strstr(line, "Plateau "))
	{
		get_filler(line, filler, 1);
		fill_map(filler, 1);
	}
	else if (ft_strstr(line, "Piece "))
	{
		get_filler(line, filler, 3);
		fill_piece(filler);
		set_nude_pieces_coord(filler);
		get_real_piece(filler);
		real_work(filler);
		if (give_answer(filler) == 1)
		{
			clean_all(filler);
			ft_strdel(&line);
			return (1);
		}
		clean_all(filler);
	}
	return (0);
}

int					main(void)
{
	char			*line;
	t_filler		filler;

	filler.my = '\0';
	while (lgnl(0, &line) > 0)
	{
		if (!line || *line == '\n' || *line == 0)
		{
			ft_strdel(&line);
			exit(1);
		}
		if (!filler.my && ft_strstr(line, "$$$")
			&& ft_strstr(line, "ariabyi.filler"))
		{
			filler.my = (line[10] == '1') ? (char)'O' : (char)'X';
			filler.enemy = (line[10] == '1') ? (char)'X' : (char)'O';
		}
		else if (dop_parsing(&filler, line) == 1)
			return (1);
		ft_strdel(&line);
	}
	return (0);
}
