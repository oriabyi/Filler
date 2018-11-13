/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <oleksandr32riabyi@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 16:53:00 by ariabyi           #+#    #+#             */
/*   Updated: 2018/08/19 16:53:00 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

# define ENEMY	-1
# define ME		-2
# define POINT	-3

# define MYSIGN			(filler->my)
# define MYSIGNSMALL	(filler->my + 32)
# define FOESSIGN		(filler->enemy)
# define FOESSIGNSMALL	(filler->enemy + 32)

# define ISMYSIGN(x)	((x) == MYSIGN || (x) == MYSIGNSMALL)
# define ISFOESSIGN(x)	((x) == FOESSIGN || (x) == FOESSIGNSMALL)

typedef struct			s_map
{
	int					size_x;
	int					size_y;
	char				**map;

}						t_map;

typedef struct			s_piece
{
	int					start_x;
	int					end_x;
	int					start_y;
	int					end_y;
	int					size_x;
	int					size_y;
	char				**piece;
	char				**real_piece;

}						t_piece;

typedef struct			s_choices
{
	int					x;
	int					y;
	int					points;
	struct s_choices	*next;
}						t_choices;

typedef struct			s_filler
{
	char				my;
	char				enemy;
	t_map				map;
	t_piece				piece;
	t_choices			*choices;
	int					**bfs;

}						t_filler;

/*
** parsing
*/
int						get_filler(char *line, t_filler *filler, int call);
int						fill_map(t_filler *filler, int code);
void					beta_fill_num_map(t_filler *filler);
void					alpha_fill_num_map(t_filler *filler);
void					get_real_piece(t_filler *filler);

/*
** get line
*/
char					*append_char(char **s, char c);
int						lgnl(int fd, char **line);

/*
** get/give answer
*/
int						check_points(t_choices *choices,
										t_filler *filler, int i, int j);
void					real_work(t_filler *filler);
int						check_touches(t_filler *filler,
									int y_got, int x_got, int touches);
int						give_answer(t_filler *filler);
t_choices				*find_the_best_choice(t_filler *filler);

/*
** fill piece
*/
void					fill_piece(t_filler *filler);

/*
** clean
*/
void					clean_all(t_filler *filler);
void					clean_choices(t_choices **choices);

#endif
