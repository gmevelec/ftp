/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 00:13:36 by gmevelec          #+#    #+#             */
/*   Updated: 2015/04/29 00:13:36 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/client.h"

int		ft_cd(int cs, char *dir)
{
	char			buf[256];
	static char		fdir[250];
	static int		true = 0;

	(void)cs;
	if (true == 0)
	{
		getcwd(fdir, sizeof(fdir));
		true = ft_strlen(fdir);
	}
	dir[0] = ' ';
	dir[1] = ' ';
	dir[2] = ' ';
	dir = ft_strtrim(dir);
	chdir((const char *)dir);
	getcwd(buf, sizeof(buf));
	if (strncmp(buf, fdir, true) != 0)
		chdir((const char *)fdir);
	free(dir);
	return (0);
}

void	ft_pwd(int cs)
{
	char	buf[256];
	int		i;

	getcwd(buf, sizeof(buf));
	i = ft_strlen(buf);
	send(cs, ft_strcat(buf, "\n"), i + 1, 0);
	recv(cs, buf, sizeof(buf), 0);
	send(cs, "END;", ft_strlen("END;"), 0);
}
