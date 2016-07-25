/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paquet.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 00:11:03 by gmevelec          #+#    #+#             */
/*   Updated: 2015/04/29 00:11:03 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAQUET_H
# define PAQUET_H

# include <stdlib.h>
# include <sys/socket.h>
# include <netdb.h>
# include <unistd.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include "libft.h"
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# define C_CLEAR "\033[H\033[2J"
# define C_RESET "\033[0m"
# define C_BOLD "\033[1m"
# define C_REV "\033[7m"
# define C_RESET "\033[0m"
# define C_WHITE "\x1B[0m"
# define C_RED "\x1B[31m"
# define C_GREEN "\x1B[32m"
# define C_YELLOW "\x1B[33m"
# define C_BLUE "\x1B[34m"
# define C_MAGENTA "\x1B[35m"
# define C_CYAN "\x1B[36m"
# define C_GRAY "\033[22;37m"

typedef	struct	s_pack
{
	int		put;
	int		get;
	char	*name;
}				t_pack;

void			init_paquet(t_pack *paquet);
void			read_paquet(t_pack *paquet, char *str);
void			send_file_to_client(char *str, int cs);
void			get_file(int cs, int fd);
void			error(char *str, int quit);
void			success(char *str);
int				check_fichier(char *str);
char			*nom_fichier(char *str);
char			*clearstr(char *str);

#endif
