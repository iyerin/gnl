 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:42:36 by iyerin            #+#    #+#             */
/*   Updated: 2017/12/04 16:42:36 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char	buf[BUFF_SIZE + 1];
	char		buf2[BUFF_SIZE + 1];
	char		*tmp;
	size_t		i;
	int			count;
	int			j;

	count = 0;
	i = 0;
	j = 0;

	if (fd < 0)
		return (-1);

	buf[BUFF_SIZE] = 0;
	if (!buf[0])
		if (read(fd, buf, BUFF_SIZE) < 0)
			return (-1);
	printf("buf = %s\n", buf);
	*line = ft_strnew(0);
	while (!ft_strchr(buf, 10))
	{
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
		if (read(fd, buf, BUFF_SIZE) <= 0)
		{
			if (*line[0])
				return (1);
			return (0);
		}
	}
	while (buf[j])
	{
		if (buf[j] == '\n')
		{
			tmp = *line;
			*line = ft_strjoin(*line, ft_strsub(buf, 0, i));
			free(tmp);
			j++;
			buf = ft_memmove(buf, buf+j, BUFF_SIZE - j);

			return (1);
		}
		i++;
		j++;
	}
	if (*line != NULL)
		free(*line);
	return (0);
}

int	main(void)
{
	int fd;
	char *line;

	fd = open("ex", O_RDONLY);

	while (get_next_line(fd, &line))
	{
		printf("==========line = %s\n", line);
		ft_strdel(&line);
	}
	close(fd);
	// while(1)
	// {
	// 	;
	// }
	return (0);
}
