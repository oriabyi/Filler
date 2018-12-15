/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:02:41 by oriabyi           #+#    #+#             */
/*   Updated: 2018/11/13 15:02:41 by oriabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int					get_filler_info(char *line, t_filler *filler, int call)
{
	if (call == 1 || call == 3)
	{
		if (call == 1)
			filler->map.size_y = ft_atoi(line + 7);
		else
			filler->piece.size_y = ft_atoi(line + 5);
		get_filler_info(line + ft_strlen(line), filler, (call == 1) ? 2 : 4);
	}
	else if (call == 2 || call == 4)
	{
		while (*line != ' ')
			line--;
		if (call == 2)
			filler->map.size_x = ft_atoi(line);
		else
			filler->piece.size_x = ft_atoi(line);
	}
	return (0);
}

void				fill_piece(t_filler *filler)
{
	char			*line;
	int				fring;
	int				c;

	c = 0;
	fring = filler->piece.size_y;
	filler->piece.piece = (char **)malloc(sizeof(char *)
			* (filler->piece.size_y + 1));
	while (fring-- && lgnl(0, &line))
	{
		filler->piece.piece[c++] = ft_strdup(line);
		ft_strdel(&line);
	}
	filler->piece.piece[c] = NULL;
}

int					fill_map(t_filler *filler, int code)
{
	int				fring;
	int				c;
	char			*line;
	int				fl;

	fl = 0;
	c = 0;
	fring = filler->map.size_y + 1;
	filler->map.map = (char **)malloc(sizeof(char *) * (fring));
	while (fring-- && lgnl(0, &line))
	{
		if (!fl && code == 1 && line && line[4] == '0')
			fl = 1;
		else
		{
			filler->map.map[c] = ft_strdup(line + 4);
			c++;
		}
		ft_strdel(&line);
	}
	filler->map.map[c] = NULL;
	init_template_num_map(filler);
	return (0);
}

void				get_real_piece(t_filler *filler)
{
	int				y;
	int				x;
	int				len_of_y;

	x = 0;
	y = filler->piece.start_y;
	len_of_y = filler->piece.end_y - filler->piece.start_y + 1;
	filler->piece.real_piece =
			(char **)malloc(sizeof(char *) * (filler->piece.size_y + 1));
	if (filler->piece.real_piece == NULL)
		return ;
	while (filler->piece.piece[y] && x < len_of_y)
	{
		filler->piece.real_piece[x] = ft_strsub(filler->piece.piece[y], 
				(unsigned)filler->piece.start_x,
				(size_t)filler->piece.end_x - filler->piece.start_x + 1);
		y++;
		x++;
	}
	filler->piece.real_piece[x] = NULL;
}
