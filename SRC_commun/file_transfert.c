/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_transfert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 00:12:43 by gmevelec          #+#    #+#             */
/*   Updated: 2015/04/29 00:12:44 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/client.h"
#include "../INCLUDE/paquet.h"
#include "../INCLUDE/serveur.h"

void		send_file_to_client(char *str, int cs)
{
	int		fd;
	int		r;
	char	buf[1024];

	fd = open(str, O_RDONLY);
	ft_memset(buf, 0, 1024);
	while ((r = read(fd, buf, 1023)) > 0)
	{
		buf[ft_strlen(buf)] = '\0';
		send(cs, buf, sizeof(buf), 0);
		recv(cs, buf, sizeof(buf), 0);
		ft_memset(buf, 0, 1024);
	}
	send(cs, "END;", ft_strlen("END;"), 0);
	close(fd);
	success("File send");
}

void		get_file(int cs, int fd)
{
	char	buf[1024];
	int		size;

	ft_memset(buf, 0, 1024);
	while ((size = recv(cs, buf, sizeof(buf), 0)) > 0)
	{
		if (!ft_strcmp(buf, "END;"))
			break ;
		buf[ft_strlen(buf)] = '\0';
		write(fd, buf, ft_strlen(buf));
		send(cs, "OK;", ft_strlen("OK;"), 0);
		ft_memset(buf, 0, 1024);
	}
	success("File received");
}
