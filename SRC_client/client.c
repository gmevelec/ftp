/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 00:11:45 by gmevelec          #+#    #+#             */
/*   Updated: 2015/06/08 16:38:54 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/paquet.h"
#include "../INCLUDE/client.h"

void	usage(char *str)
{
	ft_putstr(C_CYAN);
	ft_putstr("Usage: ");
	ft_putstr(str);
	ft_putstr(" <addr> <port>\n");
	ft_putstr(C_RESET);
	exit(-1);
}

int		create_client(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	if (ft_strcmp(addr, "localhost") == 0)
	{
		addr = ft_strcpy(addr, "127.0.0.1");
	}
	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
		error("Connect error", 1);
	return (sock);
}

void	ft_read(int sock)
{
	int		r;
	char	buf[1024];
	t_pack	paquet;

	init_paquet(&paquet);
	while ((r = read(0, buf, 1023)) > 0)
	{
		buf[r] = '\0';
		write(sock, buf, r);
		if (ft_strcmp(ft_strtrim(buf), "quit") == 0)
			break ;
		else if (ft_strcmp(ft_strtrim(buf), "ls") == 0
				|| ft_strcmp(ft_strtrim(buf), "pwd") == 0)
			ft_aff(sock);
		else
			read_paquet(&paquet, buf);
		if (paquet.get == 1)
			ft_get(sock, buf, &paquet);
		if (paquet.put == 1)
			ft_put(sock, buf, &paquet);
		ft_putstr("->");
	}
}

int		main(int ac, char **av)
{
	int		port;
	int		sock;

	if (ac != 3)
		usage(av[0]);
	port = atoi(av[2]);
	sock = create_client(av[1], port);
	ft_putstr("->");
	ft_read(sock);
	close(sock);
	return (0);
}
