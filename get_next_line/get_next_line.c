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

char	*ft_free(char **line)
{
	free(*line);
	return (NULL);
}

void	ft_cut(char str[], size_t n)
{
	size_t	i;

	i = 0;
	while (n < BUFFER_SIZE)
	{
		str[i] = str[n];
		n++;
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		str[i] = 0;
		i++;
	}
}

char	*ft_return(char buffer[], char **line, int byte)
{
	if (find_newline(buffer) != ft_strlen(buffer))
	{
		ft_cut(buffer, find_newline(buffer) + 1);
		if (find_end(*line) || ft_strlen(*line))
			return (*line);
	}
	else if (find_newline(buffer) == ft_strlen(buffer))
	{
		while (byte < BUFFER_SIZE)
		{
			buffer[byte] = 0;
			byte++;
		}
		if (find_end(*line) || ft_strlen(*line))
			return (*line);
	}
	return (ft_free(line));
}

char	*get_next_line(int fd)
{
	int				byte;
	char			*line;
	static char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strjoin(NULL, buffer);
	if (!line)
		return (ft_free(&line));
	if (find_newline(buffer) != ft_strlen(buffer))
		return (ft_return(buffer, &line, 0));
	byte = BUFFER_SIZE;
	while (byte == BUFFER_SIZE && !find_end(buffer))
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte < 0)
			return (ft_free(&line));
		buffer[byte] = 0;
		line = ft_strjoin(line, buffer);
		if (!line)
			return (ft_free(&line));
		if (byte == BUFFER_SIZE)
			byte = find_newline(buffer);
	}
	return (ft_return(buffer, &line, 0));
}
