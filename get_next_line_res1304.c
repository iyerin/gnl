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
	static char	*buf;
	char		*buf2;
	char		*tmp;
	size_t		i;
	int			count;

	count = 0;
	i = 0;
	if (fd < 0)
		return (-1);
	if (!buf)
	{
		if (read(fd, buf = ft_strnew(BUFF_SIZE), BUFF_SIZE) < 0)
		{
			free(buf);
			return (-1);
		}
		//buf2 = buf;
//// переделывать буфер.....
	}
	//buf2 = buf;
	printf("buf2_0 = %s\n", buf2);
	*line = ft_strnew(0);
	printf("buf = %s\n", buf);
	while (!ft_strchr(buf, 10))
	{
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
		buf2 = buf;
		buf = ft_strnew(BUFF_SIZE);
		printf("buf2 = %s\n", buf2);
		//free(buf2);
		if (read(fd, buf, BUFF_SIZE) <= 0)
		{
			if (*line[0])
				return (1);
			return (0);
		}
	}
	while (*buf)
	{
		if (*buf == '\n')
		{
			tmp = *line;
			*line = ft_strjoin(*line, ft_strsub(buf - i, 0, i));
			free(tmp);
			buf++;
			printf("buf_2 = %s\n", buf);
			printf("buf2_2 = %s\n", buf2);
			return (1);
		}
		i++;
		buf++;
		
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
	while(1)
	{
		;
	}
	return (0);
}
