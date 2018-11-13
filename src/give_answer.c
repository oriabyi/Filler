/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_answer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:42:15 by ariabyi           #+#    #+#             */
/*   Updated: 2018/11/13 16:42:16 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int						give_answer(t_filler *filler)
{
	char				*buff;

	filler->choices = find_the_best_choice(filler);
	if (!filler->choices)
		return (1);
	filler->choices->x -= filler->piece.start_x;
	filler->choices->y -= filler->piece.start_y;
	buff = ft_multjoinfr(6, NULL, ft_itoa(filler->choices->y)
			, " ", NULL, ft_itoa(filler->choices->x), "\n");
	ft_putstr_fd(buff, 1);
	free(buff);
	return (0);
}
