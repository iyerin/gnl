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
	static char *buf;
	size_t i;
	int count = 0;

	i = 0;
	if (fd < 0)
		return (-1);
	if (!buf)
	{
		buf = ft_strnew(BUFF_SIZE);
		if (read(fd, buf, BUFF_SIZE) < 0)
			return (-1);
	}
	if (!ft_strchr(buf, 10))
	{
		//printf("AAAAAAAAAAAAAA\n");
		count = 1;
		ft_strclr(*line);
		if (*line == NULL)
			*line = "";
		while (!ft_strchr(buf, 10))
		{
			*line = ft_strjoin(*line, buf);
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
		if (count == 0)
		{
		//	printf("huihui\n");
			ft_strclr(*line);
		}
		if (*line == NULL)
			*line = "";
		if (*buf == '\n')
		{
			*line = ft_strjoin(*line, ft_strsub(buf - i, 0, i));
			buf++;
			return (1);
		}
		i++;
		buf++;
	}
	return (0);
}
// int				main(void)
// {
// 	char		*line;
// 	int			fd;
// 	int			ret;
// 	int			count_lines;
// 	char		*filename;
// 	int			errors;

// 	filename = "gnl1_1.txt";
// 	fd = open(filename, O_RDONLY);
// 	if (fd > 2)
// 	{
// 		count_lines = 0;
// 		errors = 0;
// 		line = NULL;

// 		while (get_next_line(fd, &line))
// 			printf("==========line = %s\n", line);
// 		return (0);

// 		// while ((ret = get_next_line(fd, &line)) > 0)
// 		{
// 			// printf("HUIIII\n");
// 			// if (count_lines == 0 && strcmp(line, "1234567") != 0)
// 			// 	errors++;
// 			// printf("HUIIII\n");
// 			// count_lines++;
// 			// if (count_lines > 50)
// 			// 	break;
// 		}
// 		// printf("HUIIII\n");
// 		// close(fd);
// 		// if (count_lines != 1)
// 		// 	printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
// 		// if (errors > 0)
// 		// 	printf("-> must have read \"1234567\" instead of \"%s\"\n", line);
// 		// if (count_lines == 1 && errors == 0)
// 		// 	printf("OK\n");
// 	}
// 	else
// 		printf("An error occured while opening file %s\n", filename);
// 	return (0);
// }
// int	main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("ex", O_RDONLY);

// 	while (get_next_line(fd, &line))
// 		printf("==========line = %s\n", line);
// 	return (0);
// }
