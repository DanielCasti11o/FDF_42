/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:53:02 by dacastil          #+#    #+#             */
/*   Updated: 2025/02/20 18:53:53 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define EJE_X 1000
# define EJE_Y 1000
# define EJE_Z

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line_bonus.h"
# include "./minilibx-linux/mlx.h"

typedef struct	s_ejes
{
	int		*len_x;
	int		len_y;
	int		eje_z;
	void	*image;
}				t_ejes;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

int		ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
int		count_lines(int fd, int *len);
char	**init_map(int fd, int i, int *len);
int		**matx_to_arr(char **lines, int i, int *len);
int		*lengs(int i, int fd);
void	fr_words(char **wds);
int		ft_atoi(const char *nptr);
int		*atoi_ptr(int *ptr, char *str, int len);
int		count_spaces(char *line);
int		*rest_len(int *len, int spaces, char **lines);
int		ft_countsubstr(const char*s, char c);
char	**ft_split(char const *s, char c);
void	prints(int i, int *len);
int		*ft_intchr(int *s, int c);

#endif
