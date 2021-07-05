/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyjeong <hyjeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:46:53 by hyjeong           #+#    #+#             */
/*   Updated: 2021/07/05 15:46:53 by hyjeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *new;
    size_t  s1_len;
    size_t  s2_len;

    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    if (!s1 && !s2)
        return (0);
    else if (!s1)
        return ((char *)s2);
    else if(!s2)
        return ((char *)s1);
    new = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
    if (!new)
        return (0);
    ft_memcpy(new, s1, s1_len);
    ft_memcpy(new, s2, s2_len);
    new[s1_len + s2_len] = 0;
    return (new);
}