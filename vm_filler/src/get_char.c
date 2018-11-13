/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:20:54 by ariabyi           #+#    #+#             */
/*   Updated: 2018/11/13 19:20:55 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_filler.h"

char			*get_uo(char code)
{
	if (code == '1')
		return (strdup(TIGER));
	else if (code == '2')
		return (ft_strjoin(BACK_LMAGENTA, "O"));
	else if (code == '0')
		return (strdup(EARTH));
	return (strdup("O"));
}

char			*get_o(char code)
{
	if (code == '1')
		return (strdup(CATFACE));
	else if (code == '2')
		return (ft_strjoin(BACK_LMAGENTA, "o"));
	else if (code == '0')
		return (strdup(MOONSMYLE));
	return (strdup("o"));
}

char			*get_ux(char code)
{
	if (code == '1')
		return (strdup(BEAR));
	else if (code == '2')
		return (ft_strjoin(BACK_LCYAN, "X"));
	else if (code == '0')
		return (strdup(FIRSTQUARTERMOON));
	return (strdup("X"));
}

char			*get_x(char code)
{
	if (code == '1')
		return (strdup(PANDAFACE));
	else if (code == '2')
		return (ft_strjoin(BACK_LCYAN, "x"));
	else if (code == '0')
		return (strdup(SUNSMILE));
	return (strdup("x"));
}

char			*get_p(char code)
{
	if (code == '1')
		return (strdup(PIG));
	else if (code == '2')
		return (ft_strjoin(BACK_LWHITE, "."));
	else if (code == '0')
		return (strdup(MOON));
	return (strdup("."));
}
