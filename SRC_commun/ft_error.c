/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmevelec <gmevelec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 00:12:54 by gmevelec          #+#    #+#             */
/*   Updated: 2015/04/29 00:12:55 by gmevelec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/paquet.h"

void		error(char *str, int quit)
{
	ft_putstr(C_RED);
	ft_putstr("Error: ");
	ft_putendl(str);
	ft_putstr(C_RESET);
	if (quit)
		_exit(-1);
}

void		success(char *str)
{
	ft_putstr(C_GREEN);
	ft_putstr("Success: ");
	ft_putendl(str);
	ft_putstr(C_RESET);
}
