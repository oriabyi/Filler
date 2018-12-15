/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:41:11 by ariabyi           #+#    #+#             */
/*   Updated: 2018/11/14 17:41:12 by ariabyi          ###   ########.fr       */
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

short int			ft_pwrbase(ssize_t num, int base)
{
	short int		counter;

	base = (!base) ? 10 : base;
	counter = 1;
	if (num < 0 || base < 0)
		counter++;
	if (num == base && base < 10)
		return (counter);
	while ((num /= base))
		counter++;
	return (counter);
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
