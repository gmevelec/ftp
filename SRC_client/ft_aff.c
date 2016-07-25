/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 00:11:53 by gmevelec          #+#    #+#             */
/*   Updated: 2015/04/29 00:11:53 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/client.h"

void		ft_aff(int sock)
{
	int		size;
	char	buf[1024];

	while ((size = recv(sock, buf, sizeof(buf), 0)) > 0)
	{
		if (!ft_strcmp(buf, "END;"))
			break ;
		write (1, buf, ft_strlen(buf));
		ft_memset(buf, 0, 1024);
		send(sock, "OK;", ft_strlen("OK;"), 0);
	}
	success("Command success");
}
