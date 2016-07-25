/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 00:14:09 by gmevelec          #+#    #+#             */
/*   Updated: 2015/04/29 00:14:09 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/paquet.h"
#include "../INCLUDE/serveur.h"

void	usage(char *str)
{
	ft_putstr(C_CYAN);
	ft_putstr("Usage: ");
	ft_putstr(str);
	ft_putstr(" <port> \n");
	ft_putstr(C_RESET);
	exit(-1);
}

int		create_server(int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
		error("Bind error", 1);
	listen(sock, 10);
	return (sock);
}

void	ft_read(int cs)
{
	int					r;
	char				buf[1024];
	t_pack				paquet;

	init_paquet(&paquet);
	while ((r = read(cs, buf, 1023)) > 0)
	{
		buf[r] = '\0';
		if (ft_strncmp(buf, "cd ", 3) == 0 || ft_strncmp(buf, "cd..", 4) == 0)
			ft_cd(cs, ft_strdup(buf));
		else if (ft_strcmp(ft_strtrim(buf), "ls") == 0)
			ft_ls(cs);
		else if (ft_strcmp(ft_strtrim(buf), "pwd") == 0)
			ft_pwd(cs);
		else if (ft_strcmp(ft_strtrim(buf), "quit") == 0)
			break ;
		else
			read_paquet(&paquet, buf);
		if (paquet.get == 1)
			ft_get(cs, buf, &paquet);
		else if (paquet.put == 1)
			ft_put(cs, buf, &paquet);
	}
}

int		main(int ac, char **av)
{
	int					port;
	int					sock;
	int					cs;
	unsigned int		cslen;
	struct sockaddr_in	csin;

	if (ac != 2)
		usage(av[0]);
	port = atoi(av[1]);
	sock = create_server(port);
	while (1)
	{
		cs = accept(sock, (struct sockaddr*)&csin, &cslen);
		if (fork() == 0)
			ft_read(cs);
		close(cs);
	}
	close(sock);
	return (0);
}
