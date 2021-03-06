/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:16:57 by oriabyi           #+#    #+#             */
/*   Updated: 2017/11/20 17:09:46 by oriabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putendl_fd(char const *s, int fd)
{
	char		*buf;
	size_t		len;

	if (!s)
		return ;
	len = ft_strlen(s);
	buf = ft_strjoin(s, "\n");
	write(fd, buf, (len + 1));
	free(buf);
}
