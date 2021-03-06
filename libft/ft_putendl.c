/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:16:57 by oriabyi           #+#    #+#             */
/*   Updated: 2017/11/20 17:19:02 by oriabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putendl(char const *s)
{
	int			i;
	char		*buf;
	size_t		len;

	i = 0;
	if (!s)
		return ;
	len = ft_strlen(s);
	buf = (char *)malloc(sizeof(char) * (len));
	while (*s)
	{
		buf[i] = *s;
		i++;
		s++;
	}
	buf[i++] = '\n';
	buf[i] = '\0';
	write(1, buf, (len + 1));
	free(buf);
	ft_putstr(s);
}
