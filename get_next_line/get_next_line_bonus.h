/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:59:46 by hyjeong           #+#    #+#             */
/*   Updated: 2021/09/09 19:14:48 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

size_t	ft_strlen(char const *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		find_end(char *str);
size_t	find_newline(char const *str);
char	*ft_free(char **line);
void	ft_cut(char str[], size_t n);
char	*ft_return(char buffer[], char **line, int byte);
char	*get_next_line(int fd);

#endif
