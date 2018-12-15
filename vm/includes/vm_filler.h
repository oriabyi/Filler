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

/*
** chequered flag
*/
# define CF					"\xF0\x9F\x8F\x81"
# define TROPHY				"\xF0\x9F\x8F\x86"

# define ZERO				"\x30\xE2\x83\xA3"
# define ONE				"\x31\xE2\x83\xA3"
# define TWO				"\x32\xE2\x83\xA3"
# define THREE				"\x33\xE2\x83\xA3"
# define FOUR				"\x34\xE2\x83\xA3"
# define FIVE				"\x35\xE2\x83\xA3"
# define SIX				"\x36\xE2\x83\xA3"
# define SEVEN				"\x37\xE2\x83\xA3"
# define EIGHT				"\x38\xE2\x83\xA3"
# define NINE				"\x39\xE2\x83\xA3"

typedef struct				s_vm_filler
{
	int						size_x;
	int						size_y;
	char					code;
}							t_vm_filler;

char						*get_uo(char code);
char						*get_o(char code);
char						*get_ux(char code);
char						*get_x(char code);
char						*get_p(char code);

void						print_score_table(char code,
										char **line, int x_map);

int							*split_num(int num);
#endif
