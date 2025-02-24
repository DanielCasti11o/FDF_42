/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:53:02 by dacastil          #+#    #+#             */
/*   Updated: 2025/02/24 15:49:25 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define EJE_X 1000
# define EJE_Y 1000
# define EJE_Z

# include <math.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line_bonus.h"
# include "./minilibx-linux/mlx.h"

typedef struct s_ejes
{
	int		*len_x;
	int		len_y;
	int		**matx_z;
	float	x1;
	float	y1;
}				t_ejes;

typedef struct s_coord
{
	int	**x1;
	int	**y1;

}				t_coord;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

int		ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
int		count_lines(int fd, char *argv);
char	**init_map(int fd, int i, int *len, char *argv);
int		**matx_to_arr(char **lines, int i, int *len);
int		*lengs(int i, int fd, char *argv);
void	fr_words(char **wds);
int		ft_atoi(const char *nptr);
int		*atoi_ptr(int *ptr, char *str, int len);
int		count_spaces(char *line);
int		*rest_len(int *len, char **lines);
int		ft_countsubstr(const char*s, char c);
char	**ft_split(char const *s, char c);
void	prints(int i, int *len);
int		*ft_intchr(int *s, int c);
t_ejes	*init_ejes(int fd, char **lines, char *argv);
t_coord	*find_coord_iso(t_ejes *eje);
t_coord	*init_coord(t_ejes *eje);
void	alg_bressenham(t_ejes *eje);

#endif
