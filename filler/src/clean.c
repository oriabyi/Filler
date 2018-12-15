/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:12:49 by oriabyi           #+#    #+#             */
/*   Updated: 2018/11/13 14:12:50 by oriabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void				clean_map(t_filler *filler)
{
	int				c;

	c = 0;
	if (!filler || (!filler->map.map && !filler->num_map))
		return ;
	while (c <= filler->map.size_y)
	{
		free(filler->map.map[c]);
		free(filler->num_map[c]);
		c++;
	}
	if (filler->map.map)
	{
		free(filler->map.map);
		filler->map.map = NULL;
	}
	if (filler->num_map)
	{
		free(filler->num_map);
		filler->num_map = NULL;
	}
}

void				clean_piece(t_filler *filler)
{
	int				c;

	c = 0;
	if (!filler || (!filler->piece.piece && !filler->piece.real_piece))
		return ;
	while (c < filler->piece.size_y)
	{
		free(filler->piece.piece[c]);
		c++;
	}
	c = 0;
	while (c < (filler->piece.end_y - filler->piece.start_y + 1))
	{
		free(filler->piece.real_piece[c]);
		c++;
	}
	if (filler->piece.piece)
		free(filler->piece.piece);
	if (filler->piece.real_piece)
		free(filler->piece.real_piece);
}

void				clean_choices(t_choices **choices)
{
	t_choices		*temp;

	while (*choices)
	{
		temp = (*choices)->next;
		free(*choices);
		(*choices) = NULL;
		(*choices) = temp;
	}
	*choices = NULL;
}

void				clean_all(t_filler *filler)
{
	clean_map(filler);
	clean_piece(filler);
	clean_choices(&filler->choices);
	filler->piece = (t_piece){0, 0, 0, 0, 0, 0, NULL, NULL};
}
