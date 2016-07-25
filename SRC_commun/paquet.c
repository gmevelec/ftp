/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paquet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgay <cgay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 13:42:21 by cgay              #+#    #+#             */
/*   Updated: 2015/03/09 13:42:47 by cgay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/paquet.h"

void	init_paquet(t_pack *paquet)
{
	paquet->put = 0;
	paquet->get = 0;
}

void	read_paquet(t_pack *paquet, char *str)
{
	if (ft_strncmp(str, "put ", 4) == 0)
		paquet->put = 1;
	else if (ft_strncmp(str, "get ", 4) == 0)
		paquet->get = 1;
	else if (!ft_strncmp(str, "cd ", 3))
		success("Command success");
	else
		error("Command not found", 0);
}

int		check_fichier(char *str)
{
	int i;
	int fd;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (-1);
	else
	{
		i = 0;
		while (str[i])
			i++;
	}
	close(fd);
	return (i);
}

char	*nom_fichier(char *str)
{
	return (str + 4);
}

char	*clearstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	str[i] = '\0';
	return (str);
}
