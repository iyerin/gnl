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
	char		*tmp;
	size_t		i;
	int			count;

	count = 0;
	i = 0;
	if (fd < 0)
		return (-1);
	if (!buf)
	{
		buf = ft_strnew(BUFF_SIZE);
		if (read(fd, buf, BUFF_SIZE) < 0)
			return (-1);
	}
	*line = ft_strnew(0);
	if (!ft_strchr(buf, 10))
	{
		//ft_strclr(*line);	
		while (!ft_strchr(buf, 10))
		{
			tmp = *line;
			*line = ft_strjoin(*line, buf);
			free(tmp);
			buf = ft_strnew(BUFF_SIZE);
			if (read(fd, buf, BUFF_SIZE) <= 0)
			{
				if (*line[0])
					return (1);
				return (0);
			}
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
	// {
	// 	;
	// }
	return (0);
}