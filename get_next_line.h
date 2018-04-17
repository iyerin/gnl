/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyerin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:43:40 by iyerin            #+#    #+#             */
/*   Updated: 2017/12/04 16:43:42 by iyerin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "./libft/libft.h"
#include <stdio.h>///////////////
#include <sys/types.h>//////
#include <sys/stat.h>/////
# include <string.h>///////
#include <fcntl.h>////////

#define BUFF_SIZE 10

int	get_next_line(const int fd, char **line);

// char	*ft_strsub(char const *s, unsigned int start, size_t len);
// char	*ft_strnew(size_t size);
// char	*ft_strncpy(char *dest, const char *src, size_t n);
// size_t	ft_strlen(const char *s);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strchr(const char *s, int c);
