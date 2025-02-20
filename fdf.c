/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:55:43 by dacastil          #+#    #+#             */
/*   Updated: 2025/02/20 18:56:52 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**matx_to_arr(char **lines, int i, int *len)
{
	int	**matx_arr;
	int	j;

	j = 0;
	matx_arr = (int **)malloc((i + 1) * sizeof(int *));
	while (j < i)
	{
		printf ("len: %d\n", len[j]);
		printf("longitud = \n");
		matx_arr[j] = atoi_ptr(matx_arr[j], lines[j], len[j]);
		// printf("matx= %ls", matx_arr[j]);
		j++;
	}
	matx_arr[j] = NULL;
	return (matx_arr);
}

int	count_lines(int fd, int *len)
{
	int		i;
	char	*line;

	i = 0;
	fd = open("mapa_sencillo.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		line = get_next_line(fd);
		free(line);
	}
	printf("longitud %d\n", i);
	close(fd);
	// len = lengs(i, fd);
	// int n = 0;
	// printf("a = %d\n", len[n]);
	// while (n <= i)
	// {
	// 	printf("entra\n");
	// 	printf("a = %d\n", len[n]);
	// 	n++;
	// }
	// printf("saliendo\n");
	return (i);
}

char	**init_map(int fd, int i, int *len)
{
	char	**matx;
	int		j;

	j = 0;
	printf("lslls = %d\n", len[j]);
	if (!len)
		return (free(len), NULL);
	fd = open("mapa_sencillo.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	matx = malloc((i + 1) * sizeof(char *));
	if (!matx)
		return (free(len), NULL);
	printf("reservada memo doble p\n");
	while (j < i || get_next_line(fd) != NULL)
	{
		matx[j] = malloc(((len[j] + 1) * sizeof(char)));
		matx[j] = get_next_line(fd);
		if (!matx[j])
			return (fr_words(matx), NULL);
		j++;
	}
	matx[j] = NULL;
	return (matx);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	**lines;
	int		i;
	int		*len;
	int		j;
	int		**matx_int;

	j = 0;
	printf("start\n");
	i = count_lines(fd, len);
	len = lengs(i, fd);
	lines = init_map(fd, i, len);
	if (!lines)
		fr_words(lines);
	while (j < i)
	{
		printf("%s\n", lines[j]);
		j++;
	}
	j = 0;
	// fd = open("mapa_sencillo.txt", O_RDONLY);
	// if (fd < 0)
	// 	return (0);
	// free(len);
	// fr_words((char **)lines);
	// fr_wordsi((int **)matx_int);
	len = rest_len(len, j, lines);
	matx_int = matx_to_arr(lines, i, len);
	// printf ("len j %d", len[j]);
	int	k = 0;
	int	p = 0;
	int	ñ;
	while (k < i)
	{
		ñ = 0;
		while (ñ < len[p])
		{
			printf("%d", matx_int[k][ñ]);
			ñ++;
		}
		printf("\n");
		p++;
		k++;
	}
	prints(i, len);
}
