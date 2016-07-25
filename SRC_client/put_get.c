/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 00:12:00 by gmevelec          #+#    #+#             */
/*   Updated: 2015/04/29 00:12:00 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/paquet.h"
#include "../INCLUDE/client.h"

void	ft_get(int sock, char *buf, t_pack *paquet)
{
	int		fd;

	ft_memset(buf, 0, 1024);
	recv(sock, buf, sizeof(buf), 0);
	if (ft_strcmp(buf, "ERROR;") == 0)
		error("File doesn't exist", 0);
	else
	{
		fd = open(buf, O_RDWR | O_CREAT, 0775);
		if (fd == -1)
		{
			error("File already exist", 0);
			send(sock, "ERROR;", ft_strlen("ERROR;"), 0);
		}
		else
		{
			send(sock, "FCREE;", ft_strlen("FCREE;"), 0);
			get_file(sock, fd);
			close(fd);
		}
	}
	paquet->get = 0;
}

void	ft_put(int sock, char *buf, t_pack *paquet)
{
	int		len;
	char	*str;

	str = nom_fichier(buf);
	str = clearstr(ft_strdup(str));
	len = check_fichier(ft_strdup(str));
	if (len == -1)
	{
		error("Can't find file", 0);
		send(sock, "ERROR;", ft_strlen("ERROR;"), 0);
	}
	else
	{
		send(sock, str, ft_strlen(str), 0);
		ft_memset(buf, 0, 1024);
		recv(sock, buf, sizeof(buf), 0);
		if (ft_strcmp(buf, "ERROR;") == 0)
			error("File already exist", 0);
		else if (ft_strcmp(buf, "FCREE;") == 0)
			send_file_to_client(str, sock);
	}
	paquet->put = 0;
}
