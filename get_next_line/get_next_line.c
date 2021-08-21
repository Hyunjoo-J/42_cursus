/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 02:12:08 by hyjeong           #+#    #+#             */
/*   Updated: 2021/08/21 02:12:08 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void join_line(char **line, char *buf, int *r)
{
	static char	*re;
	char		*temp;

	if (re)
	{
		*line = ft_strdup(re);
		free(re);
		re = NULL;
	}
	else if(!*line)
		*line = ft_strdup("");
	if (*buf && *r > 0)
	{
		temp = *line;
		*line = ft_strjoin(temp, buf);
		free(temp);
	}
	temp = ft_strchr(*line, '\n');
	if (temp)
	{
		re = ft_strdup(temp + 1);
		*(temp++) = '\0';
		*r = 0;
	}
}

char	*get_next_line(int fd)
{
	char	*buf;
	char	*line;
	int		r;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	line = NULL;
	r = read(fd, buf, 0);
	if (r > 0 && buf)
	{
		r = 1;
		while (r > 0)
		{
			r = read(fd, buf, BUFFER_SIZE);
			buf[r] = 0;
			join_line(&line, buf, &r);
		}
	}
	if (line && !*line)
	{
		free(line);
		line = NULL;
	}
	free(buf);
	return(line);
}