/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_score.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:39:15 by ariabyi           #+#    #+#             */
/*   Updated: 2018/11/14 17:39:16 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_filler.h"

char				*get_digit(int digit)
{
	if (digit == 0)
		return (ZERO);
	else if (digit == 1)
		return (ONE);
	else if (digit == 2)
		return (TWO);
	else if (digit == 3)
		return (THREE);
	else if (digit == 4)
		return (FOUR);
	else if (digit == 5)
		return (FIVE);
	else if (digit == 6)
		return (SIX);
	else if (digit == 7)
		return (SEVEN);
	else if (digit == 8)
		return (EIGHT);
	else if (digit == 9)
		return (NINE);
	return (NULL);
}

char				*get_fin_char(int num)
{
	char			*ret;
	int				*arr_num;
	int				i;

	i = 1;
	if (num == 0)
		return (strdup(ZERO));
	ret = NULL;
	arr_num = split_num(num);
	while (arr_num[0])
	{
		if (ret == NULL)
			ret = ft_multjoinfr(2, get_digit(arr_num[i]), " ");
		else
			ret = ft_multjoinfr(4, NULL, ret, get_digit(arr_num[i]), " ");
		i++;
		arr_num[0]--;
	}
	free(arr_num);
	return (ret);
}

void				get_flags(char **ret, int x_map)
{
	if (x_map == 17)
		*ret = ft_multjoin(12, NULL, *ret, CF, CF, CF, CF, CF,
											CF, CF, CF, CF, "\n");
	else if (x_map == 40)
		*ret = ft_multjoin(23, NULL, *ret,
			CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF,
			CF, CF, CF, "\n");
	else if (x_map == 99)
		*ret = ft_multjoin(53, NULL, *ret,
			CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF,
			CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF,
		CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, CF, "\n");
}

void				get_score_table(char code, int o, int x, int x_map)
{
	char			*ret;

	ret = NULL;
	get_flags(&ret, x_map);
	ret = ft_multjoin(15, "\n", NULL, ret,
			NULL, get_uo(code), "   ", NULL, get_fin_char(o), "\n",
			NULL, get_ux(code), "   ", NULL, get_fin_char(x), "\n");
	if (o != x)
		ret = ft_multjoinfr(11, NULL, ret, TROPHY, TROPHY, "\t", NULL,
			(o > x) ? get_uo(code) : get_ux(code), "\t", TROPHY, TROPHY, "\n");
	else
		ret = ft_multjoinfr(15, NULL, ret, "\t", TROPHY, TROPHY, "\t", NULL,
		get_uo(code), " && ", NULL, get_ux(code), "\t", TROPHY, TROPHY, "\n");
	get_flags(&ret, x_map);
	ft_putstr(ret);
	free(ret);
}

void				print_score_table(char code, char **line_o, int x_map)
{
	char			*line_x;

	lgnl(0, &line_x);
	get_score_table(code, ft_atoi(*line_o + 9), ft_atoi(line_x + 9), x_map);
	ft_strdel(line_o);
	ft_strdel(&line_x);
}
