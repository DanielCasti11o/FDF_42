/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:35:54 by dacastil          #+#    #+#             */
/*   Updated: 2025/02/20 18:58:32 by dacastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fr_words(char **wds)
{
	int	i;

	i = 0;
	while (wds[i])
	{
		free(wds[i]);
		i++;
	}
	free(wds);
}

int	count_spaces(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

int	*atoi_ptr(int *ptr, char *str, int len)
{
	int		i;
	int		*new_ptr;
	char	**wd;

	i = 0;
	new_ptr = malloc((len) * sizeof(int));
	wd = ft_split(str, ' ');
	while (wd[i] != NULL)
	{
		// printf("str %s\n", wd[i]);
		new_ptr[i] = ft_atoi(wd[i]);
		printf("new %d ", new_ptr[i]);
		i++;
	}
	printf("\n");
	new_ptr[i] = '\0';
	// printf("numEE %d\n", new_ptr[i]);
	return (new_ptr);
}


int	*lengs(int i, int fd)
{
	int		*len;
	int		j;
	char	*str;
	int		spaces;

	str = NULL;
	len = malloc((i) * sizeof(int));
	j = 0;
	if (!len)
		return (NULL);
	fd = open("mapa_sencillo.txt", O_RDONLY);
	if (fd < 0)
		return (NULL);
	str = get_next_line(fd);
	printf("gnl %s\n", str);
	printf("gnl %d\n", ft_strlen(str));
	len[j] = (ft_strlen(str) - 1);
	printf("longi %d\n", ft_strlen(str));
	j++;
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		len[j] = (ft_strlen(str) - 1);
		j++;
	}
	free(str);
	return (len);
}

int	*rest_len(int *len, int spaces, char **lines)
{
	int	i;
	int	*res;

	i = 0;
	res = len;
	while (lines[i])
	{
		res[i] = ft_countsubstr(lines[i], ' ');
		i++;
	}
	return (res);
}
