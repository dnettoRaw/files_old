/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 18:01:02 by abeauvoi          #+#    #+#             */
/*   Updated: 2017/05/07 20:58:08 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
# define USAGE "Usage: ./fillit path/to/input_file"
# define ERR "error"
# define MAX_PIECES 26
# define BUF_SIZE 22
# define COMBINATIONS 19
# define CONTENT_SIZE 3
# define SUCCESS 0
# define FAILURE -1

/*
** Input file verification macros
*/

# define STATS_SIZE 7
# define INDEX 0
# define ROW 1
# define STEP 2
# define HASHT 3
# define NL 4
# define DOTS 5
# define FIRST_HASHT_L 6
# define MAX_HASHT 4
# define MAX_NL 5
# define MAX_DOTS 12
# define STEP_ERR FAILURE

/*
** Map-related macros & variables
*/

# define MAP_SIZE 4
# define MAX_STEP 4
# define EMPTY '.'
# define FILL 1
# define CLEAR -1

/*
** Definitions & Typedefs
*/

typedef struct	s_map_stats
{
	int			pos;
	int			size;
	char		letter;
}				t_map_stats;

int				ft_int_tab_cmp(int *a, int *b);
t_list			*ft_get_tetriminoes(int fd);
int				*ft_check_buf(char *buf, t_bool first_read);

/*
** ft_check_buf_2.c
*/

void			count_newlines(char c, int *stats, t_bool first_read);
void			count_hashmarks(char c, int *stats);
void			count_dots(char c, int *stats);
void			count_step(char c, int *stats);

/*
** map_functions.c
*/

void			*ft_delmap(char **map, int index);
char			**ft_create_map(void);
char			**ft_increase_map(char **map);
void			ft_showmap(char **map);

/*
** stats.c
*/

int				ft_get_height(t_list *tetrimino);
int				ft_get_width(t_list *tetrimino);

/*
** ft_resolve.c
*/

int				ft_resolve(t_list *tetrimino, char **map, t_map_stats *stats,
		int pos);

/*
** list_functions.c
*/

void			ft_lstincrement(t_list *list, int value);

#endif
