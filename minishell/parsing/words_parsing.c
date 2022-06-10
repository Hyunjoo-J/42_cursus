/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 23:38:09 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/06/09 23:38:26 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// 따옴표를 고려하여 공백을 기준으로 분리된 단어 개수
int	count_word(char *str)
{
	int	i;
	int	cnt;
	int	word;
	int	quote;

	i = 0;
	cnt = 0;
	word = 0;
	quote = 0;
	while (str[i])
	{
		check_quote(str[i], &quote);
		if (!is_space(str[i]) && !word)
		{
			cnt++;
			word = 1;
		}
		if (is_space(str[i]) && word && !quote)
			word = 0;
		i++;
	}
	return (cnt);
}

int	find_word(char *str, int *start)
{
	int	i;
	int	word;
	int	quote;

	skip_space(str, start);
	i = *start;
	word = 0;
	quote = 0;
	while (str[i])
	{
		check_quote(str[i], &quote);
		if (!is_space(str[i]) && !word)
			word = 1;
		if (is_space(str[i]) && word && !quote)
			break ;
		i++;
	}
	return (i);
}

<<<<<<< HEAD
char	**split_words(char *bundle)
=======
char	**split_words(char *bundle, t_info *info)
>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
{
	t_word	w_info;
	int		i;
	char	**res;

	w_info.len = count_word(bundle);
	if (w_info.len == 0)
		return (0);
	res = (char **)malloc(sizeof(char *) * (w_info.len + 1));
	if (!res)
	{
		ft_print_error(0, 0, strerror(errno));
<<<<<<< HEAD
		return (0);
=======
		free_exit(info);
>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
	}
	init_str(res, w_info.len + 1);
	i = 0;
	w_info.start = 0;
	while (i < w_info.len)
	{
		w_info.end = find_word(bundle, &(w_info.start));
		res[i] = (char *)malloc(sizeof(char) * (w_info.end - w_info.start + 1));
		if (!res[i])
		{
			ft_print_error(0, 0, strerror(errno));
			free_str(res);
<<<<<<< HEAD
			return (0);
=======
			free_exit(info);
>>>>>>> 132ce5378cc2b5ceb7d49c89c8d6abb625039c35
		}
		fill_word(bundle, res[i], w_info.start, w_info.end);
		w_info.start = w_info.end;
		i++;
	}
	return (res);
}