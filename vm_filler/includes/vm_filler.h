/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:22:09 by ariabyi           #+#    #+#             */
/*   Updated: 2018/11/13 19:22:10 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_FILLER_H
# define VM_FILLER_H

# include "../libft/libft.h"

# define BACK_LMAGENTA		"\x1b[105m"
# define BACK_LCYAN			"\x1b[106m"
# define BACK_LWHITE		"\x1b[107m"
# define BACK_DEFAULT		"\x1b[49m"

# define MOON				"\xF0\x9F\x8C\x91"
# define MOONSMYLE			"\xF0\x9F\x8C\x9A"
# define SUNSMILE		 	"\xF0\x9F\x8C\x9D"
# define EARTH		 		"\xF0\x9F\x8C\x8F"
# define FIRSTQUARTERMOON	"\xF0\x9F\x8C\x93"

# define PIG		 		"\xF0\x9F\x90\xB7"
# define BEAR				"\xF0\x9F\x90\xBB"
# define TIGER				"\xF0\x9F\x90\xAF"
# define CATFACE			"\xF0\x9F\x90\xB1"
# define PANDAFACE			"\xF0\x9F\x90\xBC"

typedef struct				s_select
{
	int						ac;
	int						fd;
	int						size_x;
	int						size_y;
	int						code;
}							t_vm_filler;

char						*get_uo(char code);
char						*get_o(char code);
char						*get_ux(char code);
char						*get_x(char code);
char						*get_p(char code);

#endif
