/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:41:11 by oriabyi           #+#    #+#             */
/*   Updated: 2018/11/14 17:41:12 by oriabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_filler.h"

int					raising_to_the_power(int num, int power)
{
	int				temp_num;

	temp_num = num;
	if (--power == 0)
		return (1);
	while (--power)
	{
		num *= temp_num;
	}
	return (num);
}

int					*split_num(int num)
{
	short			power;
	int				*ret;
	int				temp_num;
	int				i;

	i = 0;
	power = ft_pwrbase(num, 10);
	if (!(ret = (int *)malloc(sizeof(int) * (power + 1))))
		return (NULL);
	ret[i++] = power;
	while (num && power)
	{
		temp_num = num;
		while (ft_pwrbase(num, 10) == power && power > 1)
			num -= raising_to_the_power(10, power);
		while (temp_num > 9)
			temp_num /= 10;
		ret[i] = temp_num;
		i++;
		power--;
	}
	while (power--)
		ret[i++] = 0;
	return (ret);
}
