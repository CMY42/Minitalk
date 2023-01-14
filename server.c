/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmansey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:47:09 by cmansey           #+#    #+#             */
/*   Updated: 2023/01/12 11:47:09 by cmansey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//AFFICHER LE PID DU PROCESS SUR STDOUT
void	show_pid(void)
{
	pid_t	pid;
	char	*pid_str;

	pid = getpid();
	pid_str = ft_itoa(pid);
	if (!pid_str)
	{
		ft_putendl_fd("[Error]", 2);
		return;
	}
	ft_putendl_fd(pid_str, 1);
	free(pid_str);
}

int	main(void)
{
	show_pid();
	return;
}
