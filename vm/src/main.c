/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 13:19:24 by ariabyi           #+#    #+#             */
/*   Updated: 2018/06/13 13:19:25 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm_filler.h"

int					get_filler(char *line, t_vm_filler *filler, int call)
{
	if (call == 1)
	{
		filler->size_y = (int)strtol(line + 7, NULL, 10);
		get_filler(line + ft_strlen(line), filler, 2);
	}
	else if (call == 2)
	{
		while (*line != ' ')
			line--;
		filler->size_x = (int)strtol(line, NULL, 10);
	}
	return (0);
}

void				get_symbol(const char *line, char **ret, char code)
{
	int				c;

	c = 0;
	line += 4;
	while (line[c])
	{
		if (line[c] == 'O')
			*ret = ft_multjoinfr(4, NULL, *ret, NULL, get_uo(code));
		else if (line[c] == 'o')
			*ret = ft_multjoinfr(4, NULL, *ret, NULL, get_o(code));
		else if (line[c] == 'X')
			*ret = ft_multjoinfr(4, NULL, *ret, NULL, get_ux(code));
		else if (line[c] == 'x')
			*ret = ft_multjoinfr(4, NULL, *ret, NULL, get_x(code));
		else if (line[c] == '.')
			*ret = ft_multjoinfr(4, NULL, *ret, NULL, get_p(code));
		c++;
	}
}

int					fill_map(t_vm_filler *filler)
{
	int				fring;
	char			*line;
	char			*ret;

	fring = filler->size_y + 1;
	ret = NULL;
	while (fring-- && lgnl(0, &line))
	{
		if (line && line[4] == '0')
			;
		else
		{
			get_symbol(line, &ret, filler->code);
			ret = ft_multjoinfr(3, NULL, ret, "\n");
		}
		ft_strdel(&line);
	}
	ret = ft_multjoinfr(3, NULL, ret, "\n\n");
	write(1, ret, strlen(ret));
	free(ret);
	return (0);
}

static int			check_arguments(int ac, char **av, char *code)
{
	if (ac == 2)
	{
		if (ft_strlen(av[1]) != 2 || av[1][0] != '-' ||
			(av[1][1] != '0' && av[1][1] != '1' && av[1][1] != '2'))
		{
			ft_putendl_fd("usage vm: ./vm -[0, 1, 2]", 2);
			return (1);
		}
		*code = av[1][1];
	}
	else
		*code = 0;
	return (0);
}

int					main(int ac, char **av)
{
	t_vm_filler		vm;
	char			*line;
	char			code;

	if (check_arguments(ac, av, &code) == 1)
		return (1);
	vm.code = code;
	while (lgnl(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau "))
		{
			get_filler(line, &vm, 1);
			fill_map(&vm);
		}
		else if (ft_strstr(line, "=="))
		{
			print_score_table(vm.code, &line, vm.size_x);
			return (0);
		}
		ft_strdel(&line);
	}
	return (0);
}
