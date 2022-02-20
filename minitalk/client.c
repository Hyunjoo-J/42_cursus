/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjoo <hyunjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:30:46 by hyunjoo           #+#    #+#             */
/*   Updated: 2022/02/20 23:39:14 by hyunjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("usage : ./client <server pid> <message>\n", 1);
		return (0);
	}
	else if (100 < argv[1] && argv[1] < 99999)
	{
		ft_putstr_fd("Wrong pid range!");
		return(0);
	}
	return (0);
}