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

int ft_check_n(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{

	static char *buf;
	size_t i;
//	char *str;

	if (fd < 0)
		return (-1);
	i = 0;

	if (!buf)
	{
		buf = ft_strnew(BUFF_SIZE);
		if (read(fd, buf, BUFF_SIZE) < 0)
			return (-1);
	}
	if (ft_check_n(buf))
	{
		while (*buf)
		{
			if (*buf == '\n')
			{
				*line = ft_strsub(buf - i, 0, i);
				buf++;
				return (1);
			}
			i++;
			buf++;
		}
	}
	else
	{
		ft_strclr(*line);
		while (!ft_check_n(buf))
		{
			*line = ft_strjoin(*line, buf);
			buf = ft_strnew(BUFF_SIZE);
			if (read(fd, buf, BUFF_SIZE) <= 0)
			{
				if (*line[0])
				{
				//	printf("UUUUUUUUU\n");
					return (1);
				}
			//	printf("AAAAAAAAAAA\n");
				return (0);
			}
		}
		while (*buf)
		{
			if (*buf == '\n')
			{
				*line = ft_strjoin(*line, ft_strsub(buf - i, 0, i));
				buf++;
				return (1);
			}
			i++;
			buf++;
		}
	}
	return (0);
}

// int				main(void)
// {
// 	char		*line;
// 	int			fd;
// 	int			ret;
// 	char		*filename;

// 	filename = "ex";
// 	fd = open(filename, O_RDONLY);
// 	if (fd > 2)
// 	{
// 		if (close(fd) == 0)
// 		{
// 			line = NULL;
// 			ret = get_next_line(fd, &line);
// 			if (ret != -1)
// 				printf("-> must have returned '-1' when receiving a closed file descriptor\n");
// 			else
// 				printf("OK\n");
// 		}
// 		else
// 		{
// 			printf("An error occured while closing file descriptor associated with file %s\n", filename);
// 			return (0);
// 		}
// 	}
// 	else
// 		printf("An error occured while opening file %s\n", filename);
// 	return (0);
// }
int	main(void)
{
	int fd;
	char *line;

	fd = open("ex", O_RDONLY);

	while (get_next_line(fd, &line))
		printf("==========line = %s\n", line);
	return (0);
}
