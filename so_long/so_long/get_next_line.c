/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:50:23 by hyjeong           #+#    #+#             */
/*   Updated: 2022/03/20 17:50:23 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_newline(char *buf)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = ft_strlen(buf);
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (j - i);
		i++;
	}
	return (-1);
}

int	ft_return_until_new(char **mem, char **line, unsigned int new_idx)
{
	unsigned int	len;
	char			*temp;

	len = ft_strlen(*mem);
	(*mem)[len - new_idx] = '\0';
	(*line) = ft_strjoin((*mem), "");
	if ((*line) == 0)
	{
		free((*mem));
		return (-1);
	}
	temp = (*mem);
	if ((*mem)[len - new_idx + 1] != '\0')
	{
		(*mem) = ft_strjoin(&((*mem)[len - new_idx + 1]), "");
		if ((*mem) == 0)
		{
			free(*line);
			return (-1);
		}
	}
	else
		(*mem) = 0;
	free(temp);
	return (1);
}

int	ft_return_until_eof(char **mem, char **line)
{
	(*line) = ft_strjoin((*mem), "");
	if ((*line) == 0)
		return (-1);
	if ((*mem) != 0)
	{
		free(*mem);
		(*mem) = 0;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char		*mem;
	char			*temp;
	char			buf[BUFFER_SIZE + 1];
	int				cur_read;
	int				new_idx;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (mem != 0 && (new_idx = ft_newline(mem)) > 0)
		return (ft_return_until_new(&(mem), line, (unsigned int)new_idx));
	while ((cur_read = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		buf[cur_read] = '\0';
		temp = mem;
		mem = ft_strjoin(mem, buf);
		if (temp != 0)
			free(temp);
		if (mem != 0 && (new_idx = ft_newline(buf)) > 0)
			return (ft_return_until_new(&(mem), line, (unsigned int)new_idx));
		if (mem == 0 || cur_read == 0)
			break ;
	}
	if (cur_read < 0 || mem == 0)
		return (-1);
	return (ft_return_until_eof(&(mem), line));
}