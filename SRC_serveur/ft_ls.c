/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 00:13:51 by gmevelec          #+#    #+#             */
/*   Updated: 2015/04/29 00:13:52 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/serveur.h"

void	ft_ls(int cs)
{
	struct dirent	*lecture;
	DIR				*rep;
	char			buf[40];

	rep = opendir(".");
	ft_memset(buf, 0, 40);
	while ((lecture = readdir(rep)))
	{
		if (lecture->d_name[0] != '.')
		{
			send(cs, ft_strcat(lecture->d_name, "\n"),
					lecture->d_namlen + 1, 0);
			recv(cs, buf, sizeof(buf), 0);
			ft_memset(buf, 0, 40);
		}
	}
	send(cs, "END;", ft_strlen("END;"), 0);
	closedir(rep);
}
